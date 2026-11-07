/* near miss (level 3, Starship Phoenix): flags: matches only with @ps2as (inline float constants), but L03_0032C3A8.c cannot take it: func_L03_0032C8F8, already matched in that file, then differs at word +0x8; the C itself matched with --as ps2as */
#include "common.h"

/* localdecomp:start func_L03_0032CE38 */
typedef struct S_0032CE38 { char pad[0xE8]; float *v; } S_0032CE38;
typedef struct A_0032CE38 { char pad0[0x20]; unsigned char state; char pad1[0x47]; S_0032CE38 *p; } A_0032CE38;
extern float *func_L01_003F2A50(int a, int b);
extern void func_L01_003F2AF8(int a, void *b);
void func_L03_0032CE38(void *a) {
    A_0032CE38 *o = a;
    S_0032CE38 *s;
    int st = o->state;
    s = o->p;
    if ((unsigned)(st - 5) < 4) {
        if (s->v == 0) {
            s->v = func_L01_003F2A50(0, 5);
        } else {
            s->v[0] = 8.0f;
            s->v[1] = 4.0f;
            s->v[2] = 1.0f;
        }
    } else if (s->v != 0) {
        func_L01_003F2AF8(0, s->v);
        s->v = 0;
    }
}
/* localdecomp:end func_L03_0032CE38 */
