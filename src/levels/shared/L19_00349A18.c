#include "common.h"

/* localdecomp:start func_L19_00349A18 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00349A18;
typedef struct { V4_00349A18 r[4]; } M4_00349A18;

extern f32 D_L19_001DD440;
__asm__(".extern D_L19_001DD440, 4");
extern f32 D_L19_001DD444;

extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_003C5060(void *, void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L19_00349A18(u8 *o, void *target, void *out) {
    V4_00349A18 d;
    M4_00349A18 m;
    M4_00349A18 inv;
    f32 f;

    func_0038D328(&m, o + 0xF0);
    func_0038D5B0(&inv, &m);
    vec_sub_ab(&d, target, o + 0x10);
    func_003C5060(o, &d, &d, 0);
    if (*(s16 *)(o + 0xAA) == 0xE87) {
        f = D_L19_001DD440;
    } else {
        f = D_L19_001DD444;
    }
    if (d.x < 0.0f) {
        f = -f;
    }
    func_0038CF68(out, &m, f);
    vec_add_ba(out, out, o + 0x10);
}
/* localdecomp:end func_L19_00349A18 */
