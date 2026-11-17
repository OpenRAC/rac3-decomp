#include "common.h"

/* localdecomp:start func_L39_0063ED28 */
typedef struct {
    s16 id;
    s16 x;
    f32 a;
    f32 b;
    f32 c;
    u8 pad[0xB0 - 0x10];
} S_0063ED28;

typedef struct {
    u8 pad[0x800];
    S_0063ED28 s[12];
} A_0063ED28;

void func_L39_0063ED28(A_0063ED28 *a) {
    a->s[0].id = 9;
    a->s[0].x = 0;
    a->s[0].a = 0;
    a->s[0].b = 0;
    a->s[0].c = 1.0f;
    a->s[1].id = 10;
    a->s[1].x = 0;
    a->s[1].a = 0;
    a->s[1].b = 0;
    a->s[1].c = 1.0f;
    a->s[2].id = 11;
    a->s[2].x = 0;
    a->s[2].a = 0;
    a->s[2].b = 0;
    a->s[2].c = 1.0f;
    a->s[3].id = 4;
    a->s[3].x = 0;
    a->s[3].a = 0;
    a->s[3].b = 0;
    a->s[3].c = 1.0f;
    a->s[4].id = 22;
    a->s[4].x = 0;
    a->s[4].a = 0.1f;
    a->s[4].b = 0.3f;
    a->s[4].c = 1.0f;
    a->s[5].id = 23;
    a->s[5].x = 0;
    a->s[5].a = 0.1f;
    a->s[5].b = 0.3f;
    a->s[5].c = 1.0f;
    a->s[6].id = 7;
    a->s[6].x = 0;
    a->s[6].a = 0.1f;
    a->s[6].b = 0.3f;
    a->s[6].c = 1.0f;
    a->s[7].id = 8;
    a->s[7].x = 0;
    a->s[7].a = 0.1f;
    a->s[7].b = 0.3f;
    a->s[7].c = 1.0f;
    a->s[8].id = 13;
    a->s[8].x = 0;
    a->s[8].a = 0;
    a->s[8].b = 0;
    a->s[8].c = 1.0f;
    a->s[9].id = 12;
    a->s[9].x = 0;
    a->s[9].a = 0;
    a->s[9].b = 0;
    a->s[9].c = 1.0f;
    a->s[10].id = 6;
    a->s[10].x = 0;
    a->s[10].a = 0;
    a->s[10].b = 0;
    a->s[10].c = 1.0f;
    a->s[11].id = 0;
    a->s[11].x = 0;
    a->s[11].a = 0;
    a->s[11].b = 0;
    a->s[11].c = 1.0f;
}
/* localdecomp:end func_L39_0063ED28 */
