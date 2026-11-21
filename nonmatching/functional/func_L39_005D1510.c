/* functional: high. Per-tick update of an effect object attached to an owner (q[0] = owner, q = obj+0x20): frees itself when its life (s16 +0xA) says so or the owner is flagged (s8 +0x20 < 0); copies the position from q[0x10] (no owner) or from the owner plus q+0x10 transformed by the owner's joint matrix (func_003C2EC0 with joint q[4]) or its matrix at owner+0xC0, optionally sets a distance byte, then (q byte 0xC = kind 1..7) picks a facing axis (kind 1: direction from owner, 2..7: owner matrix row 0xC0/0xD0/0xE0, odd-numbered entries negated) and fades the alpha byte (top byte of +4) by the dot product with the normalised offset from D_L39_0024DE00. Kinds above 7 use an uninitialised stack axis in retail; kept uninitialised here too. VU0 vadd/vsub in plain C; same call order. */
/* localdecomp:start func_L39_005D1510 */
typedef struct { f32 x, y, z, w; } L39V4_5D1510;

extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern L39V4_5D1510 D_L39_0024DE00[];

void func_L39_005D1510(u8 *p) {
    f32 mat[16] __attribute__((aligned(16)));
    L39V4_5D1510 s10 __attribute__((aligned(16)));
    L39V4_5D1510 s20 __attribute__((aligned(16)));
    u8 *q = p + 0x20;
    u8 *owner;
    L39V4_5D1510 *axis;
    L39V4_5D1510 *ppos = (L39V4_5D1510 *)(p + 0x10);
    f32 f3, f0;
    s32 kind, w;

    if (*(s16 *)(p + 0xA) >= 0) {
        if (func_0038CB00(p + 0xA) != 0) {
            func_003CD250(p);
            return;
        }
    }
    owner = *(u8 **)q;
    if (owner == 0) {
        *ppos = *(L39V4_5D1510 *)(q + 0x10);
    } else {
        if ((s8)owner[0x20] < 0) {
            func_003CD250(p);
            return;
        }
        if (*(s32 *)(q + 4) >= 0) {
            func_003C2EC0(owner, *(s32 *)(q + 4), mat);
            func_0038D000(p + 0x10, q + 0x10, mat);
            ppos->x = ppos->x + mat[12];
            ppos->y = ppos->y + mat[13];
            ppos->z = ppos->z + mat[14];
            *(s32 *)(p + 0x1C) = 0;
        } else {
            *ppos = *(L39V4_5D1510 *)(owner + 0x10);
            func_0038D000(mat, q + 0x10, owner + 0xC0);
            ppos->x = ppos->x + mat[0];
            ppos->y = ppos->y + mat[1];
            ppos->z = ppos->z + mat[2];
            if (q[0xE] != 0) {
                s10.x = ppos->x - D_L39_0024DE00[0].x;
                s10.y = ppos->y - D_L39_0024DE00[0].y;
                s10.z = ppos->z - D_L39_0024DE00[0].z;
                s10.w = ppos->w;
                p[8] = (s32)(func_0038CE68(&s10, &D_L39_0024DE00[2]) * 6.0f);
            }
            kind = q[0xC];
            if (kind != 0) {
                axis = &s20;
                switch (kind) {
                case 1:
                    s20.x = ppos->x - *(f32 *)(owner + 0x10);
                    s20.y = ppos->y - *(f32 *)(owner + 0x14);
                    s20.z = ppos->z - *(f32 *)(owner + 0x18);
                    s20.w = ppos->w;
                    func_0038CF68(&s20, &s20, 1.0f);
                    break;
                case 2:
                    s20 = *(L39V4_5D1510 *)(owner + 0xC0);
                    break;
                case 3:
                    s20 = *(L39V4_5D1510 *)(owner + 0xC0);
                    s20.x = 0.0f - s20.x;
                    s20.y = 0.0f - s20.y;
                    s20.z = 0.0f - s20.z;
                    break;
                case 4:
                    s20 = *(L39V4_5D1510 *)(owner + 0xD0);
                    break;
                case 5:
                    s20 = *(L39V4_5D1510 *)(owner + 0xD0);
                    s20.x = 0.0f - s20.x;
                    s20.y = 0.0f - s20.y;
                    s20.z = 0.0f - s20.z;
                    break;
                case 6:
                    s20 = *(L39V4_5D1510 *)(owner + 0xE0);
                    break;
                case 7:
                    s20 = *(L39V4_5D1510 *)(owner + 0xE0);
                    s20.x = 0.0f - s20.x;
                    s20.y = 0.0f - s20.y;
                    s20.z = 0.0f - s20.z;
                    break;
                }
                s10.x = ppos->x - D_L39_0024DE00[0].x;
                s10.y = ppos->y - D_L39_0024DE00[0].y;
                s10.z = ppos->z - D_L39_0024DE00[0].z;
                s10.w = ppos->w;
                func_0038CF68(&s10, &s10, 1.0f);
                f3 = -func_0038CE68(&s10, axis) * 1.25f + 0.05f;
                if (f3 < 0.0f) {
                    *(s32 *)(p + 4) = *(s32 *)(p + 4) & 0x05FFFFFF;
                    goto tail;
                }
                if (1.0f < f3) {
                    f3 = 1.0f;
                }
                w = *(s32 *)(p + 4);
                if (q[0xF] != 0) {
                    f0 = (f32)((u32)(w & 0xFF000000) >> 24) * f3;
                } else {
                    f0 = f3 * 255.0f;
                }
                *(s32 *)(p + 4) = (w & 0xFFFFFF) | ((s32)f0 << 24);
            }
        }
    }
tail:
    *(f32 *)(p + 0xC) = *(f32 *)(p + 0xC) * *(f32 *)(q + 0x1C);
    p[8] = p[8] + q[0xD];
}
/* localdecomp:end func_L39_005D1510 */
