const CHANNEL_NAME = 'namgen_dm_handout';
const STORAGE_KEY = 'namgen_dm_handout_latest';

/**
 * Broadcast a spoiler-free handout payload to any open /handout player window
 * and persist it in localStorage so newly opened player windows load immediately.
 */
export function broadcastPlayerHandout(payload) {
  if (typeof window === 'undefined') return null;

  const enriched = {
    ...payload,
    sentAt: new Date().toISOString(),
  };

  try {
    localStorage.setItem(STORAGE_KEY, JSON.stringify(enriched));
  } catch (_) {}

  try {
    if ('BroadcastChannel' in window) {
      const ch = new BroadcastChannel(CHANNEL_NAME);
      ch.postMessage(enriched);
      ch.close();
    }
  } catch (_) {}

  return enriched;
}

export function readLatestHandout() {
  if (typeof window === 'undefined') return null;
  try {
    const raw = localStorage.getItem(STORAGE_KEY);
    return raw ? JSON.parse(raw) : null;
  } catch (_) {
    return null;
  }
}

export function clearPlayerHandout() {
  return broadcastPlayerHandout({ kind: 'idle', title: 'Awaiting DM Handout' });
}

export { CHANNEL_NAME, STORAGE_KEY };
