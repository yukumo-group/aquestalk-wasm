/* Voice catalogue and engine loading shared by the test suites. */
import {
  ENGINES,
  AQTK10_VOICES,
  setEngineRoot,
  loadEngine,
} from '../../demo/engines.js';

export const ENGINE_IDS = ['aqtk1', 'aqtk2', 'aqtk10'];

export const ENGINE_NAMES = {
  aqtk1: 'AquesTalk1',
  aqtk2: 'AquesTalk2',
  aqtk10: 'AquesTalk10',
};

function catalogue(id) {
  const info = ENGINES.find((engine) => engine.id === id);
  if (!info) throw new Error(`unknown engine in catalogue: ${id}`);
  return info;
}

export const VOICE_IDS = {
  aqtk1: catalogue('aqtk1').voices.map((voice) => voice.id),
  aqtk2: catalogue('aqtk2').voices.map((voice) => voice.id),
  aqtk10: Object.keys(AQTK10_VOICES),
};

export function voiceLabel(engineId, voice) {
  if (!voice) return 'default';
  return voice.replace(/\.phont$/, '');
}

/** Advertised sample rate for one voice (AquesTalk10's fsc changes it). */
export function expectedRate(engineId, voice) {
  if (engineId === 'aqtk10') {
    const fsc = AQTK10_VOICES[voice]?.fsc ?? 100;
    return 16000 * fsc / 100;
  }
  return 8000;
}

export async function loadAllEngines(url) {
  if (url) setEngineRoot(url);
  const engines = {};
  for (const id of ENGINE_IDS) engines[id] = await loadEngine(id);
  return engines;
}

export function voiceEntries() {
  return ENGINE_IDS.flatMap((engineId) =>
    VOICE_IDS[engineId].map((voice) => ({
      engineId,
      voice,
      label: voiceLabel(engineId, voice),
      rate: expectedRate(engineId, voice),
    })));
}
