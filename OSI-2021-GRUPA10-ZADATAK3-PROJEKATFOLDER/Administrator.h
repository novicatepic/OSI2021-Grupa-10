#pragma once
#include <iostream>
#include "Radnik.h"

class Administrator :virtual public Radnik {
private:

public:
	bool dodajRadnika(Radnik r);
	bool suspendujRadnika(Radnik r);
};