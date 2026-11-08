#include "common.h"

typedef struct State_0031ABF8 {
    /* 0x00 */ s32 id0;
    /* 0x04 */ s32 id1;
    /* 0x08 */ s32 flags;
    /* 0x0C */ s16 level;
    /* 0x0E */ s16 active;
    /* 0x10 */ f32 angles[3];
    /* 0x1C */ s32 mode;
    /* 0x20 */ f32 firstAngle;
    /* 0x24 */ f32 firstVelocity;
    /* 0x28 */ f32 secondAngle;
    /* 0x2C */ f32 secondVelocity;
    /* 0x30 */ f32 firstSpeed;
    /* 0x34 */ f32 firstStep;
    /* 0x38 */ f32 secondSpeed;
    /* 0x3C */ f32 secondStep;
    /* 0x40 */ u8 entries[0x4A];
    /* 0x8A */ u8 present;
    /* 0x8B */ u8 pad8B[2];
    /* 0x8D */ u8 update;
} State_0031ABF8;

/* localdecomp:start func_L02_0031A438 */
extern s32 D_L02_001F1600[];
extern void func_L01_0044BB08(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern void func_00388BD0(void *, void *);
extern f32 func_00388978(f32);
extern void func_L01_0044B860(void *, f32 *, f32 *, f32, f32, f32);
extern void func_L01_0044B920(void *, f32 *, f32 *, f32, f32, f32);
extern void func_00388EB8(void *, void *, void *);
extern void func_003BF360(void *, void *);
extern void func_L01_0044C1D0(void *, void *);

void func_L02_0031A438(char *self)
{
    float angles[4];
    char mat[48];
    State_0031ABF8 *st = *(State_0031ABF8 **)(self + 0x68);
    int i;
    int last;

    switch (*(unsigned char *)(self + 0x20)) {
    case 0:
        if (*(long *)st == -1)
            break;
        {
            int alpha = 255;
            *(unsigned char *)(self + 0x30) = alpha;
        }
        func_L01_0044BB08(self, st->entries, 0x50, st->id1, st->id0, st->flags, 7, 0);
        if (!st->present) {
            func_003BD360(self);
            break;
        }
        if (!st->mode) {
            st->update = 1;
            *(unsigned short *)(self + 0x34) |= 0x104;
            func_00388BD0(self + 0xC0, self + 0xF0);
        }
        if (st->firstAngle != 0.0f)
            st->firstAngle *= 0.017453292f;
        st->firstVelocity = func_00388978(st->firstAngle) * st->firstSpeed;
        st->active = 1;
        self[0x20] = 1;
        break;
    case 1:
        if (!st->active)
            break;
        if (D_L02_001F1600[0] != st->level)
            break;
        if (st->firstStep > 0.0f)
            func_L01_0044B860(self, &st->firstAngle, &st->firstVelocity, st->firstSpeed,
                              st->firstStep * 0.017453292f * 0.0166666675f, -1.0f);
        if (st->secondStep > 0.0f) {
            func_L01_0044B920(self, &st->secondAngle, &st->secondVelocity,
                              st->secondSpeed * 0.017453292f,
                              st->secondStep * 0.017453292f * 0.0166666675f, 0.00581776444f);
            if (st->update)
                func_00388BD0(self + 0xC0, self + 0xF0);
        }
        if (!st->mode) {
            angles[0] = st->angles[0] * 0.017453292f * 0.0166666675f;
            angles[1] = st->angles[1] * 0.017453292f * 0.0166666675f;
            angles[2] = st->angles[2] * 0.017453292f * 0.0166666675f;
            func_00388BD0(mat, angles);
            func_00388EB8(self + 0xC0, self + 0xC0, mat);
            if (st->secondStep > 0.0f)
                func_003BF360(self + 0xC0, self + 0xF0);
        } else {
            angles[0] = st->angles[0] * 0.017453292f * 0.0166666675f;
            angles[1] = st->angles[1] * 0.017453292f * 0.0166666675f;
            angles[2] = st->angles[2] * 0.017453292f * 0.0166666675f;
            func_00388BD0(mat, angles);
            i = 0;
            do {
                func_00388EB8(st->entries + i * 0x50, st->entries + i * 0x50, mat);
                last = *(unsigned char *)(st->entries + i * 0x50 + 0x4A);
                i++;
            } while (last != 1);
        }
        func_L01_0044C1D0(self, st->entries);
        break;
    }
}
/* localdecomp:end func_L02_0031A438 */
