import { NextResponse } from 'next/server';
import { getSettings, saveSettings, maskSettingsForClient } from '../../../lib/localStore';
import { getCppEngineStatus } from '../../../lib/cppNamgen';

export const dynamic = 'force-dynamic';

export async function GET() {
  try {
    const settings = await getSettings();
    return NextResponse.json({
      settings: maskSettingsForClient(settings),
      cppEngine: getCppEngineStatus(),
    });
  } catch (err) {
    return NextResponse.json({ error: err?.message || 'Failed to read settings' }, { status: 500 });
  }
}

export async function POST(request) {
  try {
    const body = await request.json();
    const saved = await saveSettings(body);
    return NextResponse.json({
      settings: maskSettingsForClient(saved),
      cppEngine: getCppEngineStatus(),
    });
  } catch (err) {
    return NextResponse.json({ error: err?.message || 'Failed to save settings' }, { status: 500 });
  }
}
