import { NextResponse } from 'next/server';
import {
  getCampaignById,
  renderCampaignMarkdown,
  slugify,
} from '../../../../../lib/localStore';

export const dynamic = 'force-dynamic';

export async function GET(request, context) {
  try {
    const { id } = await context.params;
    const { searchParams } = new URL(request.url);
    const format = searchParams.get('format') || 'md';

    const campaign = await getCampaignById(id);
    if (!campaign) {
      return NextResponse.json({ error: 'Campaign not found' }, { status: 404 });
    }

    const base = slugify(campaign.name);
    if (format === 'json') {
      return new NextResponse(JSON.stringify(campaign, null, 2), {
        status: 200,
        headers: {
          'Content-Type': 'application/json; charset=utf-8',
          'Content-Disposition': `attachment; filename="${base}.json"`,
        },
      });
    }

    const md = renderCampaignMarkdown(campaign);
    return new NextResponse(md, {
      status: 200,
      headers: {
        'Content-Type': 'text/markdown; charset=utf-8',
        'Content-Disposition': `attachment; filename="${base}.md"`,
      },
    });
  } catch (err) {
    console.error('[campaign export] error:', err);
    return NextResponse.json({ error: err?.message || 'Export failed' }, { status: 500 });
  }
}
