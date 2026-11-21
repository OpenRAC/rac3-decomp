/* functional: high. EXACT per check.py: matches byte for byte at level 03 and 06 with @ps2as (check.py); the case labels are shifted by one (state 1 is an empty case) so the jump table has retail's first entry as the end label. Eight-state machine for a swinging/rotating Phoenix object: spring of the value at +0x18, rotation of the child at +0x4B0, blend at +0x508, offset (+0x4E4,+0x4E8) on a circle. */
typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_003998B0;

/* localdecomp:start func_L03_0039AA48 */
extern f32 D_L03_001DE354;
__asm__(".extern D_L03_001DE354, 4");
extern f32 D_L03_001DE358;
__asm__(".extern D_L03_001DE358, 4");
extern f32 D_L03_001DE35C;
__asm__(".extern D_L03_001DE35C, 4");
extern f32 D_L03_001DE360;
__asm__(".extern D_L03_001DE360, 4");
extern f32 D_L03_001DE364;
__asm__(".extern D_L03_001DE364, 4");
extern f32 D_L03_001DE368;
__asm__(".extern D_L03_001DE368, 4");
extern f32 D_L03_001DE36C;
__asm__(".extern D_L03_001DE36C, 4");
extern f32 D_L03_001DE370;
__asm__(".extern D_L03_001DE370, 4");

extern void func_L03_0039AE90(u8 *m);
extern void func_L01_0044F450(void *, void *);
extern f32 func_003C41A0(void *, void *, f32, f32, f32, f32);
extern void func_L01_004450F0(u8 *o, s32 a, s32 b);
extern s32 func_L03_0039AFB0(Moby_003998B0 *m);
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

typedef struct T_0039AA48 {
    u8 p0[0x4B0];
    f32 f4B0;
    u8 p4B4[0x1C];
    f32 f4D0;
    u8 p4D4[0x10];
    f32 f4E4;
    f32 f4E8;
    u8 p4EC[0x10];
    f32 f4FC;
    u8 p500[8];
    f32 f508;
} T_0039AA48;

void func_L03_0039AA48(u8 *o) {
    T_0039AA48 *t;
    f32 s;
    f32 w;

    t = *(T_0039AA48 **)(o + 0x68);
    func_L03_0039AE90(o);
    func_L01_0044F450(o, t);
    switch (o[0x20]) {
    case 1:
        break;
    case 2:
        func_003C41A0(o + 0x18, (u8 *)t + 0x500, D_L03_001DE35C, D_L03_001DE358 * 0.00040000002f, D_L03_001DE358 * 0.00040000002f, D_L03_001DE354 * 0.020000001f);
        if (*(f32 *)(o + 0x18) <= D_L03_001DE35C) {
            func_L01_004450F0(o, 3, -1);
        }
        if (func_L03_0039AFB0((Moby_003998B0 *)o) != 0) {
            return;
        }
        func_L01_004450F0(o, 8, -1);
        return;
    case 3:
        func_L01_00448890(&t->f4B0, (u8 *)t + 0x504, 0, D_L03_001DE368 * 0.017453292f, D_L03_001DE364 * 0.017453292f * 0.00040000002f, D_L03_001DE364 * 0.017453292f * 0.00040000002f, D_L03_001DE360 * 0.017453292f * 0.020000001f);
        t->f4D0 = t->f4B0;
        if (t->f4B0 == D_L03_001DE368 * 0.017453292f) {
            func_L01_004450F0(o, 4, -1);
        }
        if (func_L03_0039AFB0((Moby_003998B0 *)o) != 0) {
            return;
        }
        func_L01_004450F0(o, 7, -1);
        return;
    case 4:
        t->f508 = t->f508 + D_L03_001DE370 * 1.2f;
        if (1.0f <= t->f508) {
            t->f508 = 1.0f;
            func_L01_004450F0(o, 5, -1);
        }
        s = (1.0f - func_0038D098(t->f508 * 3.1415927f)) * 0.5f;
        t->f4E4 = -D_L03_001DE36C * func_0038D0B0(t->f4D0) * s;
        t->f4E8 = D_L03_001DE36C * func_0038D098(t->f4D0) * s;
        if (func_L03_0039AFB0((Moby_003998B0 *)o) != 0) {
            return;
        }
        func_L01_004450F0(o, 6, -1);
        return;
    case 5:
        if (func_L03_0039AFB0((Moby_003998B0 *)o) != 0) {
            return;
        }
        func_L01_004450F0(o, 6, -1);
        return;
    case 6:
        t->f508 = t->f508 - D_L03_001DE370 * 1.2f;
        if (t->f508 <= 0.0f) {
            t->f508 = 0.0f;
            func_L01_004450F0(o, 7, -1);
        }
        w = (1.0f - func_0038D098(t->f508 * 3.1415927f)) * 0.5f;
        t->f4E4 = -D_L03_001DE36C * func_0038D0B0(t->f4D0) * w;
        t->f4E8 = D_L03_001DE36C * func_0038D098(t->f4D0) * w;
        if (func_L03_0039AFB0((Moby_003998B0 *)o) == 0) {
            return;
        }
        func_L01_004450F0(o, 4, -1);
        return;
    case 7:
        func_L01_00448890(&t->f4B0, (u8 *)t + 0x504, 0, 0.0f, D_L03_001DE364 * 0.017453292f * 0.00040000002f, D_L03_001DE364 * 0.017453292f * 0.00040000002f, D_L03_001DE360 * 0.017453292f * 0.020000001f);
        t->f4D0 = t->f4B0;
        if (t->f4B0 == 0.0f) {
            func_L01_004450F0(o, 8, -1);
        }
        if (func_L03_0039AFB0((Moby_003998B0 *)o) == 0) {
            return;
        }
        func_L01_004450F0(o, 3, -1);
        return;
    case 8:
        func_003C41A0(o + 0x18, (u8 *)t + 0x500, t->f4FC, D_L03_001DE358 * 0.00040000002f, D_L03_001DE358 * 0.00040000002f, D_L03_001DE354 * 0.020000001f);
        if (t->f4FC <= *(f32 *)(o + 0x18)) {
            func_L01_004450F0(o, 1, -1);
        }
        if (func_L03_0039AFB0((Moby_003998B0 *)o) != 0) {
            func_L01_004450F0(o, 2, -1);
        }
        return;
    default:
        break;
    }
}
/* localdecomp:end func_L03_0039AA48 */
