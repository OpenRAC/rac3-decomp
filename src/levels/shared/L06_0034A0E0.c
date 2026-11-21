#include "common.h"

/* localdecomp:start func_L06_0034A0E0 */
typedef struct { u8 pad0[0x8F0]; u32 c[4]; u8 pad900[0x938 - 0x900]; s32 f938; s32 f93C; s32 f940; } S;
typedef struct { u8 pad0[0x68]; S *p; } O;
void func_L06_0034A0E0(O *o) {
    S *s = o->p;
    s32 v = *(s32 *)((u8 *)s + 0x904);
    if (v == 0) {
        s->c[0] = 0x7F1010FF; s->c[1] = 0x6FFFFFFF; s->c[2] = 0x30101080; s->c[3] = 0x101030;
        s->f938 = 0xFF; s->f93C = 0; s->f940 = 0;
    } else if (v == 1) {
        s->c[0] = 0x7F10FF10; s->c[1] = 0x6FFFFFFF; s->c[2] = 0x30108010; s->c[3] = 0x103010;
        s->f938 = 0; s->f93C = 0xFF; s->f940 = 0;
    } else if (v == 2) {
        s->c[0] = 0x7FFF1010; s->c[1] = 0x6FFFFFFF; s->c[2] = 0x30801010; s->c[3] = 0x301010;
        s->f938 = 0; s->f93C = 0; s->f940 = 0xFF;
    } else if (v == 3) {
        s->c[0] = 0x7F007F7F; s->c[1] = 0x6FFFFFFF; s->c[2] = 0x20006666; s->c[3] = 0x3030;
        s->f938 = 0x75; s->f93C = 0x75; s->f940 = 0;
    } else if (v == 4) {
        s->c[0] = 0x7F96006B; s->c[1] = 0x6FFFFFFF; s->c[2] = 0x2096006B; s->c[3] = 0x450030;
        s->f938 = 0x6B; s->f93C = 0; s->f940 = 0x96;
    } else if (v == 5) {
        s->c[0] = 0x7F004C8C; s->c[1] = 0x6FFFFFFF; s->c[2] = 0x20004C8C; s->c[3] = 0x2C42;
        s->f938 = 0x8C; s->f93C = 0x4C; s->f940 = 0;
    } else {
        s->c[0] = 0x7F1010FF; s->c[1] = 0x6FFFFFFF; s->c[2] = 0x30101080; s->c[3] = 0x101030;
        s->f938 = 0xFF; s->f93C = 0; s->f940 = 0;
    }
}
/* localdecomp:end func_L06_0034A0E0 */
