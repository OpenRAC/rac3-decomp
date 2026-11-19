/* functional: medium. Plain C for retail's vector asm; control flow ported block by block from the PAL asm. */
typedef struct { u8 pad[0x70]; u8 *data; u8 pad74[0x20]; int index; } M_CFF8;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_CFF8;
extern u8 *D_L39_002637C0[];
extern u8 *D_L39_003CE540[];
extern u8 D_L39_0024DE80[];
extern s32 D_L39_0024B858[];
extern u8 D_L39_0025F760[];
extern f32 D_001DFF98_sda;
extern s32 D_001D7B50_sda;
extern void func_0038CDF8(void *dst, void *a, void *b, float f);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L01_003E8F20(s32 idx, float a, float b, float c);
extern int func_L01_00446720(void *obj);
extern float func_0038CE68(void *a, void *b);
extern void func_0038CE20(void *dst, void *src, float f);
extern void func_0038CF68(void *dst, void *src, float f);
extern float func_0038D0C8(float x);
extern void func_0038CE90(void *dst, void *a, void *b);
extern void func_0038D890(void *dst, void *src, void *axis, float angle);
extern int func_L39_0056CC48(void *m);
extern int func_L01_003E7AA0(void *m);
extern int func_L01_003E77B0(void *m);
extern int func_0038CB00(void *p);
extern float func_003C3BE8(float a, float b, float c);
extern float func_0038CEA8(void *v);
extern int func_003D3CB0(void *a, void *b, s32 c, s32 d, s32 e);
extern int func_L01_003E4168(void *pos);
extern void func_L39_0057B4C0(s32 player, s32 reset_timer);

void func_L39_0056CFF8(M_CFF8 *m) {
    V_CFF8 tmp0, tmp1, tmp2, tmp3, tmp4;
    u8 *base = m->data + 0x60;
    u8 *motion = m->data + 0x180;
    u8 *state = m->data + 0x210;
    u8 *hero = D_L39_0024DE80 + m->index * 0x460;
    u8 *sub = hero + 0x150;
    int flag = 0, collected = 0, count, k, changed;
    u8 **in = D_L39_002637C0;
    u8 **out = D_L39_003CE540;
    float f, len, dot;
    u8 *obj;
    s16 a;

    f = *(float *)(motion + 0x2C) - *(float *)(state + 0x30) + 1.5f;
    func_0038CDF8(&tmp0, m->data + 0xB0, hero, 0.5f);
    count = func_003D4D00(&tmp0, 1, (void *)*(s32 *)(sub + 0xF0), 0, f * 0.5f);
    for (; count > 0; count--, in++) {
        obj = *in;
        a = *(s16 *)(obj + 0xAA);
        if ((u32)(((u16)a) - 0x191F) < 2)
            func_L01_003E8F20(m->index, -1.0f, -1.0f, D_001DFF98_sda);
        if (*(s32 *)(obj + 0x98) == 0) continue;
        if (func_L01_00446720(obj)) {
            if (*(s16 *)(obj + 0xAA) != 0xB6B) continue;
        }
        a = *(s16 *)(obj + 0xAA);
        if (a == 0x477 || a == 0xB || a == 0x1AD6 || a == 0x1ADA || a == 0x1944 || a == 0x18DE
            || a == 0x1F89 || a == 0x1CAA || a == 0x109E || a == 0x109F) {
            V_CFF8 *p = (V_CFF8 *)(obj + 0x10), *bp = (V_CFF8 *)(base + 0x50);
            tmp0.x = p->x - bp->x; tmp0.y = p->y - bp->y; tmp0.z = p->z - bp->z;
            dot = func_0038CE68(base + 0x30, &tmp0);
            func_0038CE20(&tmp1, base + 0x30, dot);
            tmp2.x = tmp0.x - tmp1.x; tmp2.y = tmp0.y - tmp1.y; tmp2.z = tmp0.z - tmp1.z;
            func_0038CF68(&tmp2, &tmp2, 1.0f);
            dot = func_0038CE68(&tmp2, motion);
            dot = func_0038D0C8(dot / (*(float *)(motion + 0x2C) - *(float *)(state + 0x30)));
            dot = 1.5707964f - dot;
            if (dot < 0.0f) dot = -dot;
            if (dot < 0.43621f) {
                func_0038CE90(&tmp3, motion, base + 0x30);
                func_0038CF68(&tmp3, &tmp3, 1.0f);
                if (0.0f < func_0038CE68(&tmp3, &tmp0))
                    func_0038D890(motion, motion, base + 0x20, -0.017453292f);
                else
                    func_0038D890(motion, motion, base + 0x20, 0.017453292f);
            }
        } else {
            *out++ = obj;
            collected++;
            *(s32 *)(obj + 0x98) = 0;
        }
    }
    if (*(s16 *)(state + 0x4E) == 0) {
        flag = func_L39_0056CC48(m) != 0;
        if (func_L01_003E7AA0(m)) flag = 1;
    }
    if (func_L01_003E77B0(m)) flag = 1;
    f = *(float *)(motion + 0x2C);
    if (f - *(float *)(state + 0x30) < 1.5f) {
        *(u16 *)(state + 0x34) = 0x683;
        *(float *)(state + 0x30) = f - 1.5f;
    }
    if (*(u8 **)(hero + 0x54) != 0) {
        s16 t = *(s16 *)(*(u8 **)(hero + 0x54) + 0x86);
        if (t == 4 || t == 0x51) {
            if (*(s32 *)(hero + 0x454) < 8) *(u16 *)(state + 0x34) = 0x589;
        }
    }
    {
        int toA, tmpv;
        u16 s34;
        if (*(s16 *)(state + 0x3A) != 0) toA = 1;
        else if (flag) toA = 0;
        else {
            s34 = *(u16 *)(state + 0x34);
            if ((u16)(s34 - 1) < 0x682) toA = 1;
            else {
                u8 *q = *(u8 **)(sub + 0x134);
                toA = (*(float *)(q + 0x100) < 0.3f && *(float *)(q + 0x104) < 0.3f);
            }
        }
        if (toA) {
            if (func_0038CB00(state + 0x34)) *(s16 *)(state + 0x3A) = 0;
            if (*(s16 *)(state + 0x3A) != 0) {
                if (func_0038CB00(state + 0x34)) *(s16 *)(state + 0x3A) = 0;
            }
            *(float *)(state + 0x30) =
                func_003C3BE8(0.0f, *(float *)(state + 0x30), (float)*(s16 *)(state + 0x34) / 1667.0f);
        } else {
            if (*(s16 *)(state + 0x34) < 0x684) *(u16 *)(state + 0x34) = 0x683;
            else func_0038CB00(state + 0x34);
        }
    }
    func_0038CF68(motion, motion, *(float *)(motion + 0x2C) - *(float *)(state + 0x30));
    {
        V_CFF8 *mo = (V_CFF8 *)motion, *bp = (V_CFF8 *)(base + 0x50);
        tmp0.x = mo->x + bp->x; tmp0.y = mo->y + bp->y; tmp0.z = mo->z + bp->z;
    }
    changed = 0;
    if (!(D_L39_0024B858[m->index] & 0x20)) {
        changed = 1;
        D_L39_0024B858[m->index] |= 0x20;
    }
    if (*(s32 *)(sub + 0x100) == 0x31) {
        *(s16 *)(state + 0x4C) = 0;
    } else if (D_001D7B50_sda != -1) {
        *(s16 *)(state + 0x4C) = 0;
    } else if (*(s16 *)(state + 0x4E) != 0) {
        *(s16 *)(state + 0x4C) = 0;
    } else if (!func_003D3CB0(base + 0x50, &tmp0, D_L39_0024B858[m->index], *(s32 *)(sub + 0xF0), 0)) {
        *(s16 *)(state + 0x4C) = 0;
    } else if (func_L01_003E4168(D_L39_0025F760)) {
        *(s16 *)(state + 0x4C) = 0;
    } else {
        *(u16 *)(state + 0x4C) = *(u16 *)(state + 0x4C) + 1;
        if (!(*(s16 *)(state + 0x4C) < 0x19)) func_L39_0057B4C0(m->index, 1);
    }
    {
        V_CFF8 *mp = (V_CFF8 *)((u8 *)m + 0x30), *bp = (V_CFF8 *)(base + 0x50);
        tmp3.x = mp->x - tmp0.x; tmp3.y = mp->y - tmp0.y; tmp3.z = mp->z - tmp0.z;
        len = func_0038CEA8(&tmp3);
        tmp2.x = mp->x - bp->x; tmp2.y = mp->y - bp->y; tmp2.z = mp->z - bp->z;
        func_0038CF68(&tmp2, &tmp2, 1.0f);
        if (30.0f < len && *(s32 *)(hero + 0x454) >= 9) {
            func_L39_0057B4C0(m->index, 0);
        } else if (*(s32 *)(sub + 0x11C) > 0 && 0.0f < func_0038CE68(&tmp2, sub + 0x80) && len < 20.0f
                   && func_003D3CB0(mp, &tmp0, D_L39_0024B858[m->index], *(s32 *)(sub + 0xF0), 0)) {
            func_L39_0057B4C0(m->index, 0);
        }
    }
    if (changed) D_L39_0024B858[m->index] &= ~0x20;
    for (k = 0; k < collected; k++) {
        u8 *o = D_L39_003CE540[k];
        *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
    }
}
