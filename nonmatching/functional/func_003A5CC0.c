/* functional: medium. Written from PAL's assembly (no draft). Vector math that retail does on VU0 (lqc2/vsub.xyz/vadd.xyz/sqc2) is plain float code keeping the w lane as retail does (w comes from the first operand); quadword copies are 128-bit copies. Retail's stack slots overlap (the target vector at sp+0x20 later holds the 4x4 matrix filled by func_003C3278); here they are separate locals. Where retail reads an uninitialised w (the fixed target vector's w lane), the C reads an uninitialised w too: only the w of obj->pos can pick it up (path with D_001D545C == 11 and func_003D4068 failing). */
typedef int Q_3A5CC0 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; s32 x10; } Sub24_3A5CC0;
typedef struct Obj_3A5CC0 {
    u8 p0[0x10];
    f32 pos[4];                 /* 0x10 */
    u8 p20[4];
    Sub24_3A5CC0 *x24;          /* 0x24 */
    u8 p28[0x34 - 0x28];
    u16 flags;                  /* 0x34 */
    u8 p36[0x68 - 0x36];
    u8 *x68;                    /* 0x68 */
    u8 p6C[0x98 - 0x6C];
    s32 x98;                    /* 0x98 */
    u8 p9C[0xBC - 0x9C];
    u8 xBC;                     /* 0xBC */
    u8 pBD[3];
    f32 rot[8];                 /* 0xC0 */
    f32 xE0[4];                 /* 0xE0 */
    f32 xF0[4];                 /* 0xF0 */
} __attribute__((aligned(16))) Obj_3A5CC0;
typedef struct {
    u8 p0[0x80];
    f32 x80[4];                 /* 0x80: D_1A4C60 */
    u8 p90[0xB0 - 0x90];
    f32 xB0[4];                 /* 0xB0: D_1A4C90 */
    u8 pC0[0xE0 - 0xC0];
    f32 xE0[4];                 /* 0xE0: D_1A4CC0 */
    u8 pF0[0x35C - 0xF0];
    Obj_3A5CC0 *x35C;
    s32 x360;
    u8 p364[0x25C0 - 0x364];
    s32 x25C0;                  /* D_1A71A0 */
} __attribute__((aligned(16))) S_1A4BE0_3A5CC0;
/* D_1A4BE0 .. D_1A71A0 are one structure: the decomp's names for its fields */
extern S_1A4BE0_3A5CC0 D_1A4BE0;
extern Obj_3A5CC0 *D_22D8B0[];
extern s32 D_001D5B94;
extern s32 D_001D5BEC;
extern s32 D_001D545C;
extern Q_3A5CC0 D_227660;
extern u8 D_16C650[];
extern u8 D_22D900[];
extern u8 D_22D908[];
extern u8 D_001D6F00[], D_001D6F10[], D_001D6F20[], D_001D6F30[], D_001D6F40[], D_001D6F50[], D_001D6F60[];
extern f32 D_001D6F6C;
extern f32 D_001D6F70;
extern u8 D_001D6F74[];
extern u8 D_001D6F80[];
extern void func_003A5AF8(Obj_3A5CC0 *);
extern void func_0038D348(void *, void *, f32);
extern void func_0038D200(void *, void *, f32);
extern void func_0038D230(void *, void *, f32);
extern void func_003C56D8(void *, void *, s32);
extern void func_003C5608(void *, void *, s32);
extern void func_003C4C60(void *, void *);
extern f32 func_0038D2E0(void *, void *);
extern f32 func_0038D318(void *, void *);
extern void func_003C4158(void *, void *, s32, s32, f32);
extern f32 func_003C40E8(void *, s32, s32, f32);
extern void func_0038D950(void *, void *);
extern void func_0038D970(void *, void *);
extern void func_0038D3E0(void *, void *, void *);
extern s32 func_003D4068(void *, void *, s32, s32, s32);
extern s32 func_0038E000(void *, f32);
extern void func_003C4558(void *, void *, f32, f32, f32, f32);
extern void func_003C3278(void *, s32, void *);
extern void func_003C6A38(void *, void *, s32, s32, void *, void *, void *, void *, void *, void *, void *);
extern void func_003C6D48(void *, void *, void *);
extern void func_003C8190(void *);
extern s32 func_003C5110(void *);
extern void func_003C5160(void *, void *, void *, void *);

void func_003A5CC0(Obj_3A5CC0 *obj, s32 arg1) {
    f32 tgt[4] __attribute__((aligned(16)));
    f32 dir[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    f32 v60[4] __attribute__((aligned(16)));
    f32 v70[4] __attribute__((aligned(16)));
    f32 v80[4] __attribute__((aligned(16)));
    f32 v90[4] __attribute__((aligned(16)));
    Obj_3A5CC0 **pp;
    Obj_3A5CC0 *q;
    void *focus;
    s32 adjust;
    s32 i, hit;
    f32 f, sign;

    if (D_22D8B0[0] == 0) {
        /* first call: build the object list, then place the camera */
        func_003A5AF8(obj);
        if (D_001D5B94 == 0) {
            adjust = 1;
            if (D_001D5BEC != 0) {
                if (D_001D545C == 11) {
                    tgt[0] = 526.9220f;     /* 0x4403BB02 */
                    tgt[1] = 200.0f;
                    tgt[2] = 819.2620f;     /* 0x444CD0C5 */
                    for (i = 24; i >= 0; i--) {
                        sign = 1.0f;
                        if (0.0f < D_1A4BE0.xB0[3]) sign = -1.0f;
                        dir[0] = tgt[0] - obj->pos[0];
                        dir[1] = tgt[1] - obj->pos[1];
                        dir[2] = tgt[2] - obj->pos[2];
                        dir[3] = tgt[3];
                        func_0038D348(dir, dir, sign);
                        func_0038D200(dir, dir, -1.0f);
                        func_003C56D8(obj->rot, dir, 0);
                    }
                    func_003C4C60(obj->rot, obj->xF0);
                    if (func_0038D2E0(D_1A4BE0.xB0, obj->pos) < 100.0f) {
                        sign = 1.0f;
                        if (0.0f < D_1A4BE0.xB0[3]) sign = -1.0f;
                        v50[0] = tgt[0] - obj->pos[0];
                        v50[1] = tgt[1] - obj->pos[1];
                        v50[2] = tgt[2] - obj->pos[2];
                        v50[3] = tgt[3];
                        func_0038D348(v50, v50, sign);
                        *(Q_3A5CC0 *)dir = *(Q_3A5CC0 *)tgt;
                        func_0038D200(v40, v50, 1.0f);
                        v40[0] = v40[0] + obj->pos[0];
                        v40[1] = v40[1] + obj->pos[1];
                        v40[2] = v40[2] + obj->pos[2];
                        if (func_003D4068(v40, dir, 2, (s32)obj, 0) != 0) {
                            *(Q_3A5CC0 *)obj->pos = D_227660;
                        } else {
                            *(Q_3A5CC0 *)obj->pos = *(Q_3A5CC0 *)dir;
                        }
                    }
                } else {
                    for (i = 7; i >= 0; i--) {
                        func_003C5608(obj, tgt, 0);
                        func_003C56D8(obj->rot, tgt, 0);
                    }
                    func_003C4C60(obj->rot, obj->xF0);
                    if (func_0038D2E0(D_1A4BE0.xB0, obj->pos) < 100.0f) {
                        func_003C4158(obj->pos, obj->pos, 0, 0, 0.5f);
                    }
                }
            } else {
                f = func_003C40E8(obj->pos, 0, 0, 0.5f);
                if (f == 0.0f) {
                    adjust = 0;
                } else {
                    obj->pos[2] = f;
                }
            }
            func_0038D950(D_16C650, obj->rot);
            *(Q_3A5CC0 *)(D_16C650 + 0x30) = *(Q_3A5CC0 *)obj->pos;
            if (adjust) {
                func_0038D348(tgt, obj->xE0, D_001D6F6C);
                obj->pos[0] = obj->pos[0] + tgt[0];
                obj->pos[1] = obj->pos[1] + tgt[1];
                obj->pos[2] = obj->pos[2] + tgt[2];
            }
            D_001D6F70 = obj->pos[2];
        }
        func_003C6A38(obj, D_22D900, 0, 0, D_001D6F30, D_001D6F40, D_001D6F00, D_001D6F60,
                      D_001D6F50, D_001D6F10, D_001D6F20);
    }

    focus = 0;
    if (D_001D5B94 == 0) {
        func_0038D230(tgt, obj, 1.0f / 1024.0f);
        tgt[3] = tgt[3] + 1.0f;
        if (func_0038E000(tgt, 50.0f) == -1) {
            return;
        }
        if (D_001D5B94 == 0) {
            hit = 0;
            if (func_0038D318(obj->pos, D_1A4BE0.x80) < 6.0f) {
                if (obj->xBC == 0) {
                    *(Q_3A5CC0 *)tgt = *(Q_3A5CC0 *)D_1A4BE0.xE0;
                    tgt[2] = tgt[2] + 2.0f;
                    hit = func_003D4068(D_1A4BE0.xE0, tgt, 0, D_1A4BE0.x25C0, 0) != 0;
                } else {
                    *(Q_3A5CC0 *)tgt = *(Q_3A5CC0 *)D_1A4BE0.xE0;
                    tgt[2] = tgt[2] + 2.0f;
                    if (func_003D4068(D_1A4BE0.xE0, tgt, 0, D_1A4BE0.x25C0, 0) != 0) {
                        hit = 1;
                    } else {
                        dir[0] = obj->pos[0] - D_1A4BE0.x80[0];
                        dir[1] = obj->pos[1] - D_1A4BE0.x80[1];
                        dir[3] = obj->pos[3];
                        dir[2] = 0.0f;
                        func_0038D348(dir, dir, 0.4f);
                        tgt[0] = tgt[0] + dir[0];
                        tgt[1] = tgt[1] + dir[1];
                        tgt[2] = tgt[2] + dir[2];
                        hit = func_003D4068(D_1A4BE0.xE0, tgt, 0, D_1A4BE0.x25C0, 0) != 0;
                    }
                }
            }
            obj->xBC = hit;
            if (hit != 0 && D_001D5BEC == 0) {
                func_003C4558(D_22D908, D_001D6F74, D_001D6F70 + 0.75f, 0.000800000038f, 0.000800000038f, 0.0200000014f);
            } else {
                func_003C4558(D_22D908, D_001D6F74, D_001D6F70, 0.000800000038f, 0.000800000038f, 0.0200000014f);
            }
        }
    }
    func_003C3278(obj, 1, m);
    *(Q_3A5CC0 *)v60 = *(Q_3A5CC0 *)&m[12];

    if (arg1 == 0 && D_001D545C == 11) {
        sign = 1.0f;
        if (0.0f < D_1A4BE0.xB0[3]) sign = -1.0f;
        v70[0] = 526.9220f;
        v70[1] = 200.0f;
        v70[2] = 819.2620f;
        v80[0] = v70[0] - obj->pos[0];
        v80[1] = v70[1] - obj->pos[1];
        v80[2] = v70[2] - obj->pos[2];
        v80[3] = v70[3];
        func_0038D348(v80, v80, sign);
        func_0038D200(v80, v80, -1.0f);
        func_003C56D8(obj->rot, v80, 0);
        func_003C4C60(obj->rot, obj->xF0);
    }

    /* every object in the list follows obj */
    pp = D_22D8B0;
    if (*pp != 0) {
        do {
            q = *pp;
            if (obj->flags & 1) {
                q->x98 = 0;
                q->flags |= 0x41;
            } else {
                q->flags &= 0xFFBE;
                q->x98 = q->x24->x10;
            }
            {
                Q_3A5CC0 p = *(Q_3A5CC0 *)obj->pos;
                *(Q_3A5CC0 *)v70 = *(Q_3A5CC0 *)q->pos;
                *(Q_3A5CC0 *)v80 = *(Q_3A5CC0 *)q->xF0;
                *(Q_3A5CC0 *)q->pos = p;
            }
            func_0038D970(q->rot, m);
            if (D_001D5B94 == 2 || D_001D5B94 == 6) {
                func_0038D3E0(v90, D_001D6F80, q->rot);
                q->pos[0] = v60[0] + v90[0];
                q->pos[1] = v60[1] + v90[1];
                q->pos[2] = v60[2] + v90[2];
                q->pos[3] = v60[3];
            }
            func_003C4C60(q->rot, q->xF0);
            func_003C8190(q);
            {
                u8 *sub = q->x68;
                v90[0] = q->pos[0] - v70[0];
                v90[1] = q->pos[1] - v70[1];
                v90[2] = q->pos[2] - v70[2];
                v90[3] = q->pos[3];
                if (func_003C5110(q) != 0) {
                    func_003C5160(sub + 0x30, v90, v80, q->xF0);
                }
            }
            if (D_1A4BE0.x360 >= 2 && D_1A4BE0.x35C == q) {
                focus = D_1A4BE0.x80;
            }
            if (D_001D5B94 != 0) {
                q->x98 = 0;
                obj->x98 = 0;
            } else if (obj->x98 != 0) {
                q->x98 = q->x24->x10;
            }
            pp++;
        } while (*pp != 0);
    }

    if (D_001D545C == 12 || D_001D545C == 18) {
        obj->xF0[1] = 0;
        obj->xF0[0] = 0;
        return;
    }
    if (D_001D5B94 == 0) {
        func_003C6D48(obj, D_22D900, focus);
    }
}
