/*******************************************************************************
*   Taras Shchybovyk
*   (c) 2018 Taras Shchybovyk
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#include "eos_parse_unknown.h"
#include "os.h"
#include <string.h>

static void printString(const char in[], const char fieldName[], actionArgument_t *arg) {
    uint32_t inLength = strlen(in);
    uint32_t labelLength = strlen(fieldName);

    os_memset(arg->label, 0, sizeof(arg->label));
    os_memset(arg->data, 0, sizeof(arg->data));

    os_memmove(arg->label, fieldName, labelLength);
    os_memmove(arg->data, in, inLength);
}

void parseUnknownAction(uint8_t *buffer, uint32_t bufferLength, uint8_t argNum, actionArgument_t *arg) {
    if (argNum == 0) {
        printString("Arbitrary Data", "WARNING", arg);
    } else if (argNum == 1) {
        printString("Signing may be dangerous and on your own risk", "WARNING", arg);
    }
}