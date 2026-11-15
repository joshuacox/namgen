'use strict';

export function createSseStream(request, executor) {
  const encoder = new TextEncoder();
  const controller = new AbortController();

  if (request?.signal) {
    if (request.signal.aborted) {
      controller.abort();
    } else {
      request.signal.addEventListener('abort', () => controller.abort(), { once: true });
    }
  }

  const stream = new ReadableStream({
    async start(streamCtrl) {
      let closed = false;
      const send = (event, data) => {
        if (closed || controller.signal.aborted) return;
        try {
          const payload = typeof data === 'string' ? data : JSON.stringify(data);
          streamCtrl.enqueue(encoder.encode(`event: ${event}\ndata: ${payload}\n\n`));
        } catch {}
      };
      const close = () => {
        if (closed) return;
        closed = true;
        try { streamCtrl.close(); } catch {}
      };

      try {
        await executor({ send, signal: controller.signal });
      } catch (err) {
        if (!controller.signal.aborted) {
          send('error', { message: err?.message || 'Stream error' });
        }
      } finally {
        close();
      }
    },
    cancel() {
      controller.abort();
    },
  });

  return new Response(stream, {
    headers: {
      'Content-Type': 'text/event-stream; charset=utf-8',
      'Cache-Control': 'no-cache, no-transform',
      Connection: 'keep-alive',
      'X-Accel-Buffering': 'no',
    },
  });
}
