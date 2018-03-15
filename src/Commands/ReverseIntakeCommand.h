#ifndef ReverseIntakeCommand_H
#define ReverseIntakeCommand_H

#include "Commands/Command.h"

class ReverseIntakeCommand : public Command {
public:
	ReverseIntakeCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ReverseIntakeCommand_H
