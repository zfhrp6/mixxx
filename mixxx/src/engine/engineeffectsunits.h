#ifndef ENGINEEFFECTSUNITS_H
#define ENGINEEFFECTSUNITS_H

#include "engineobject.h"
#include "effectsunits/effectsunitsinstance.h"

class EffectsUnitsInstance;

class EngineEffectsUnits : public EngineObject {
public:
	EngineEffectsUnits();
	~EngineEffectsUnits();

	static EngineEffectsUnits * getEngine();
	void process(const CSAMPLE *pIn, const CSAMPLE *pOut, const int iBufferSize);
	void process(const CSAMPLE *pIn, const CSAMPLE *pOut, const int iBufferSize, const QString Source);

	void addInstanceToSource(EffectsUnitsInstance * Instance, QString Source);
	QList<EffectsUnitsInstance *> * getInstancesBySource(QString Source);

private:
	static EngineEffectsUnits * m_pEngine;			// We only want one engine running, here's the pointer to it.
	QList<EffectsUnitsInstance * > * m_OnChannel1;	// Processing queue
	QList<EffectsUnitsInstance * > * m_OnChannel2;	// for Channel1 e 2

};

#endif
