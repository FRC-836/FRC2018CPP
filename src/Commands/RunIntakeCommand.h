#ifndef RunIntake_H
#define RunIntake_H

#include "Commands/Command.h"

class RunIntakeCommand : public frc::Command {
public:
	RunIntakeCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RunIntake_H
