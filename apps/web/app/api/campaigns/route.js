import { NextResponse } from 'next/server';
import {
  getVault,
  getVaultInfo,
  createCampaign,
  saveCampaign,
  setActiveCampaign,
  deleteCampaign,
} from '../../../lib/localStore';

export const dynamic = 'force-dynamic';

export async function GET() {
  try {
    const vault = await getVault();
    return NextResponse.json({
      vault,
      storage: getVaultInfo(),
    });
  } catch (err) {
    console.error('[campaigns GET] error:', err);
    return NextResponse.json({ error: err?.message || 'Failed to read local vault' }, { status: 500 });
  }
}

export async function POST(request) {
  try {
    const body = await request.json();
    const { action } = body || {};

    let vault;
    if (action === 'create') {
      vault = await createCampaign(body);
    } else if (action === 'save' && body.campaign) {
      vault = await saveCampaign(body.campaign);
    } else if (action === 'switch' && body.campaignId) {
      vault = await setActiveCampaign(body.campaignId);
    } else if (action === 'delete' && body.campaignId) {
      vault = await deleteCampaign(body.campaignId);
    } else {
      return NextResponse.json({ error: 'Invalid campaign action' }, { status: 400 });
    }

    return NextResponse.json({
      vault,
      storage: getVaultInfo(),
    });
  } catch (err) {
    console.error('[campaigns POST] error:', err);
    return NextResponse.json({ error: err?.message || 'Failed to update local vault' }, { status: 400 });
  }
}
