#include "common.h"

/* localdecomp:start func_L39_0063A030 */
extern void func_L39_005F33E0(s32, s32, s32);

void func_L39_0063A030(u8 *a0, s32 a1, s32 a2) {
    func_L39_005F33E0(a1, a2, *(s32 *)(a0 + 9508));
}
/* localdecomp:end func_L39_0063A030 */

/* localdecomp:start func_L39_0063A058 */
extern void func_L39_005F33E0(s32, s32, s32);
typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    s32 wDC;
} S_637810_Ent;

typedef struct {
    u8 pad0[0x80];
} S_637810_Slot;

typedef struct {
    u8 pad0[0x2400];
    s32 handles[9];
    s32 keys[9];
} S_637810;

extern S_637810_Slot D_L39_001FE020[];

void func_L39_0063A058(S_637810 *self, s32 i, s32 key, s32 arg) {
    s32 h = self->handles[i];
    if (h != -1) {
        S_637810_Ent *e = (S_637810_Ent *)&D_L39_001FE020[h];
        if (e->wDC == key && e->bD0 != 0) {
            goto done;
        }
    }
    self->handles[i] = ((s32 (*)(s32, s32, s32))func_L39_005F33E0)(arg, 4, key);
done:
    self->keys[i] = key;
}
/* localdecomp:end func_L39_0063A058 */

/* localdecomp:start func_L39_0063A0F0 */
extern void func_L39_005F3088(s32);

void func_L39_0063A0F0(S_637810 *self) {
    s32 i;
    for (i = 0; i < 9; i++) {
        if (self->keys[i] != 0) {
            if (self->handles[i] != -1) {
                S_637810_Ent *e = (S_637810_Ent *)&D_L39_001FE020[self->handles[i]];
                if (e->wDC == self->keys[i] && e->bD0 != 0) {
                    func_L39_005F3088(self->handles[i]);
                }
            }
            self->handles[i] = -1;
        } else {
            if (self->handles[i] != -1) {
                S_637810_Ent *e = (S_637810_Ent *)&D_L39_001FE020[self->handles[i]];
                if (e->wDC == *(s32 *)((u8 *)self + 0x2524) && e->bD0 != 0) {
                    func_L39_005F3088(self->handles[i]);
                }
            }
            self->handles[i] = -1;
        }
    }
}
/* localdecomp:end func_L39_0063A0F0 */

/* localdecomp:start func_L39_0063A1E8 */
typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Type1;
/* from rac4-decomp's func_0051FD70 */
void func_L39_0063A1E8(char *a, s32 b, s32 c, s32 d)
{
    Type1 *p = (Type1 *)(a + 0x23F0);
    s32 i = 0;
    do {
        i++;
        if (!p->f0) {
            p->f0 = 1;
            p->f6 = d;
            p->f4 = c;
            p->f2 = b;
            return;
        }
        p++;
    } while (i < 2);
}
/* localdecomp:end func_L39_0063A1E8 */

/* localdecomp:start func_L39_0063A230 */
extern void func_L39_0063A4E0(u8 *p, s32 a, s32 b, s32 en, s32 t);
extern void func_L39_0063A030(u8 *a0, s32 a1, s32 a2);
typedef struct {
    s16 active;
    s16 type;
    s16 timer;
    s16 arg;
} Slot_6379E8;

typedef struct {
    u8 pad0[891];
    u8 b891;
    u8 pad1[9200 - 892];
    Slot_6379E8 slots[2];
} Self_6379E8;

extern s32 func_0038CB00(s16 *timer);

void func_L39_0063A230(Self_6379E8 *self) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (func_0038CB00(&self->slots[i].timer) == 2) {
            self->slots[i].active = 0;
            if (self->slots[i].type == 28) {
                ((void (*)(Self_6379E8 *self, s32 a, s32 b, s32 c, s32 d))func_L39_0063A4E0)(self, self->b891, 1, 1, 50);
            } else {
                ((void (*)(Self_6379E8 *self, s32 type, s32 arg))func_L39_0063A030)(self, self->slots[i].type, self->slots[i].arg);
            }
        }
    }
}
/* localdecomp:end func_L39_0063A230 */

/* localdecomp:start func_L39_0063A2E8 */
void func_L39_0063A2E8(u8 *p) {
    func_L39_0063A4E0(p, p[0x37B], 0, 1, 50);
    func_L39_0063A1E8((char *)p, 0x1C, 6, 0);
}
/* localdecomp:end func_L39_0063A2E8 */

/* localdecomp:start func_L39_0063A330 */
extern void func_L39_005F33E0(s32, s32, s32);

void func_L39_0063A330(u8 *o) {
    s32 id;

    switch (*(s16 *)(*(u8 **)(o + 0x2524) + 0xAA)) {
    case 0x1E69:
        id = 0x1B;
        break;
    case 0x18CB:
    case 0x1ADC:
    case 0x1CFD:
    case 0x1E59:
    case 0x1E7A:
        id = 0x1C;
        break;
    case 0x1CFB:
    case 0x1CFC:
        id = 0x1D;
        break;
    case 0x1E68:
        id = 0x1E;
        break;
    case 0x1E07:
        id = 0x1F;
        break;
    case 0x16DB:
        id = 0x20;
        break;
    case 0x18CD:
    case 0x1CFE:
    case 0x1E4C:
    case 0x1E4D:
    case 0x1E83:
        id = 0x21;
        break;
    case 0x1E65:
        id = 0x22;
        break;
    case 0x18CC:
        id = 0x23;
        break;
    case 0x18CF:
        id = 0x24;
        break;
    case 0x171C:
    default:
        id = 0x13;
        break;
    }
    func_L39_005F33E0(id, 0, *(s32 *)(o + 0x2524));
}
/* localdecomp:end func_L39_0063A330 */

/* localdecomp:start func_L39_0063A4E0 */
extern void func_L39_005F3668(s32, s32, s32, s32, s32, s32);
void func_L39_0063A4E0(u8 *p, s32 a, s32 b, s32 en, s32 t) {
    s32 f;
    if (en) {
        f = 0;
        if (*(s32 *)(p + 0x4A0)) {
            f = *(s32 *)(p + 0x4C8) == 14;
        }
        t = (t << 10) / 30;
        func_L39_005F3668(a, b, f, 0, *(s32 *)(p + 0x2524), t);
    }
}
/* localdecomp:end func_L39_0063A4E0 */

/* localdecomp:start func_L39_0063A540 */
typedef union Buf_0063A540 {
    u8 b[8];
    u32 w[2];
} Buf_0063A540;

extern u8 D_L39_004997E0[];
extern s32 func_L39_00632C48(void *, f32);
extern void func_L39_0063A4E0(u8 *p, s32 a, s32 b, s32 en, s32 t);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_0063A540(u8 *q) {
    Buf_0063A540 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

void func_L39_0063A540(u8 *o) {
    s32 id;

    if ((get_state_0063A540(o + 0x19E6) ^ 1) != 0) {
        return;
    }
    if ((get_state_0063A540(o + 0x19E4) ^ 2) == 0 && *(s32 *)(o + 0x2F0) < 12) {
        return;
    }
    id = o[0x37B];
    if ((get_state_0063A540(o + 0x19E4) ^ 2) == 0 && *(s32 *)(o + 0x2F0) == 18) {
        func_L39_0063A4E0(o, id, 0, 1, 30);
    }
    switch (*(u8 *)(*(u8 **)(o + 0x2524) + 0x43)) {
    case 3:
        if (*(s32 *)(o + 0x61C) != 0) {
            return;
        }
        if (func_L39_00632C48(o, 49.5f)) {
            func_L39_0063A4E0(o, id, 0, 1, 30);
        }
        if (func_L39_00632C48(o, 17.0f)) {
            func_L39_0063A4E0(o, id, 1, 1, 30);
        }
        break;
    case 4:
        if (*(s32 *)(o + 0x61C) != 0) {
            return;
        }
        if (func_L39_00632C48(o, 12.5f)) {
            func_L39_0063A4E0(o, id, 0, 1, 30);
        }
        if (func_L39_00632C48(o, 1.0f)) {
            func_L39_0063A4E0(o, id, 1, 1, 30);
        }
        break;
    case 20:
        if (*(s32 *)(o + 0x61C) != 0) {
            return;
        }
        if (func_L39_00632C48(o, 8.0f)) {
            func_L39_0063A4E0(o, id, 0, 1, 30);
        }
        if (func_L39_00632C48(o, 21.0f)) {
            func_L39_0063A4E0(o, id, 1, 1, 30);
        }
        break;
    }
}
/* localdecomp:end func_L39_0063A540 */
