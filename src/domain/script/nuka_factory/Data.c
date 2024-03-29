#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "Data.h"
#include "../../../commons/Type.h"
#include "../../../commons/Strings.h"
#include "../../Status.h"
#include "../TaleScript.h"
#include "Script.h"

int location = OUTSIDE_ROOM_ENTRANCE;

int status = game_continue;
int length = 0;

boolean input = false;
char* buffer = "";

int experience = 0;
int multiplier = 1;
char* range = RANGE_NUKA;

int poison = 0;
boolean dry = true;

int caps = 0;
boolean fatMan = false;

boolean ghoulWaked = false;
int password = 0;
boolean secutityAlerted = false;