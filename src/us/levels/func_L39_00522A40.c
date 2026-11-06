#include "common.h"

/* localdecomp:start func_L39_00522A40 */
extern s32 func_0019D650(void);
extern void func_L39_00523328(char *, char *);
extern void func_L01_00463938(char *, char *, s32, f32, f32);

void func_L39_00522A40(char *object) {
    char *state = *(char **)(object + 0x68);
    s32 first = *(s32 *)(state + 0x38);
    s32 last = *(s32 *)(state + 0x34);
    s32 end;
    s32 index;
    s32 random;
    end = first + 2;
    index = end - last;
    if (index <= -1) {
        index += 0x23;
    }
    random = func_0019D650();
    if (random % 7 == 0) {
        func_L39_00523328(object, *(char **)(state + 0x5C) + (index << 6));
    }
    random = func_0019D650();
    if (random % 0x16 == 0) {
        char *entry = *(char **)(state + 0x5C) + (index << 6);
        func_L01_00463938(entry, entry + 0x10, 0, -1.0f, 0.0f);
    }
}
/* localdecomp:end func_L39_00522A40 */
