/* functional: high. Compiles; all 55 jal targets identical to retail as a multiset. Sibling of func_L01_0032E2D0 (ten-state variant, jump table order 0..9 contiguous), built from the same reading. This function is the first one in its file, so the declarations here (Query struct, D_ names, callee prototypes) must go in the file prelude; D_001DCE4C_sda/D_001DCE30_sda/D_001DCE38_sda are the gp slots 0x59C/0x580/0x588. Case 3 jumps into case 4's p+0x70 check, as retail. */
typedef struct {
    vu0_v4 from, to, velocity;
    u8 *hit;
    s32 *info;
    s32 kind;
    f32 radius, step, scale;
    s32 zero48, zero4c, enabled;
    u8 *surface;
    s32 enabled58;
    f32 skin;
} Query_0032B408;

extern s32 D_001DCE4C_sda;
__asm__(".extern D_001DCE4C_sda, 4");
extern f32 D_001DCE30_sda;
__asm__(".extern D_001DCE30_sda, 4");
extern f32 D_001DCE38_sda;
__asm__(".extern D_001DCE38_sda, 4");
extern void *D_001E1090_sda;
__asm__(".extern D_001E1090_sda, 4");
extern void *D_L01_001E1098[];
extern u8 D_L01_00276E60[];
extern u8 *D_L01_00278350[];
extern f32 D_L01_002784E0[][3];
extern u8 *D_L01_001DAFEC;
extern u8 D_001A4BE0[];
extern vu0_v4 D_001A4C60;
extern s32 D_001A71A4[];

extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_004C8688(s32, void *, s32);
extern void func_L01_004C7D40(void *, void *, f32);
extern s32 func_L01_004C7E70(Query_0032B408 *, s32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_L01_004CB018(void *);
extern void func_L01_004C67A0(void *, void *, s32, f32, f32, f32, f32);
extern u8 *func_L01_003016B0(void *, s32, f32, f32);
extern s32 func_L01_004CADE8(void *, void *);
extern void func_L01_0032CA80(void);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00444F38(void *, s32, s32, s32, s32);
extern void func_L01_004C8668(s32);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_004395E0(void *);
extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
extern s32 func_L01_004C80F8(void *, s32);
extern void func_L01_0032BF70(void *);
extern void func_L01_0032C220(void *);
extern void func_L01_0032C390(void *);
extern void func_L01_0032BCB0(void *);
extern void func_L01_0032BDD8(void *);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern void func_L01_004C81A8(s32);
extern void func_L01_004CAE60(void *, s32);
extern void func_003C2880(void *);
extern void func_L01_0032C5D0(void *);
extern void func_L01_0040E050(void *);
extern s32 func_0038CAD0(u8 *);
extern void func_L01_0032CB38(void *);
extern void func_L01_0032BE90(void *);
extern void func_L01_0032BEF0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_0032E2B0(void *);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_L01_0032CF48(void *);

void func_L01_0032B408(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    vu0_v4 old_position, direction, forward, quaternion, axis, rotation[3], delta, inverse[4];
    Query_0032B408 query;
    s32 info[2];
    s32 collision, c, idx;
    f32 angle;
    u8 *o;

    switch (m[0x20]) {
    case 0:
        m[0x20] = 1;
        *(s32 *)(p + 0x6C) = D_001DCE4C_sda;
        D_001DCE4C_sda = (D_001DCE4C_sda + 1) % 100;
        *(s32 *)(m + 0x98) = 0;
    case 1:
        func_L01_004C7D98(m + 0x10, &direction);
        func_0038CF68(&forward, m + 0xE0, 1.0f);
        func_0038CE90(&axis, &forward, &direction);
        angle = func_0038CE68(&forward, &direction) * 0.5f;
        func_0038CE20(&quaternion, &axis, func_0038D0B0(angle));
        quaternion.w = func_0038D098(angle);
        func_0038D810(&quaternion, rotation);
        func_0038D5F0(m + 0xC0, rotation, m + 0xC0);
        old_position = *(vu0_v4 *)(m + 0x10);
        vec_add_ba(m + 0x10, m + 0x10, p);
        func_L01_004C8688(*(s8 *)(p + 0x4F), p, 0);
        func_L01_004C7D40(m + 0x10, p, D_001DCE30_sda * 0.00040000002f);
        query.from = old_position;
        query.to = *(vu0_v4 *)(m + 0x10);
        info[0] = 0;
        info[1] = 0xC5A;
        query.velocity = *(vu0_v4 *)p;
        query.info = info;
        query.radius = 0.1f;
        query.step = D_001DCE38_sda;
        query.scale = 0.5555556f;
        query.skin = 0.074f;
        query.hit = m;
        query.kind = 2;
        query.zero48 = 0;
        query.zero4c = 0;
        query.enabled = 1;
        query.enabled58 = 1;
        collision = func_L01_004C7E70(&query, -1);
        *(vu0_v4 *)(m + 0x10) = query.to;
        *(vu0_v4 *)p = query.velocity;
        if (func_L01_004CB2D8() != 0) {
            func_L01_004CAB30(m + 0x10, m + 0x10);
        }
        if (collision != 2) {
            break;
        }
        if (query.hit != 0) {
            s16 h = *(s16 *)(query.hit + 0xAA);
            if (h == 0xCB || h == 0x1366 || h == 0x1367) {
                func_0038CE20(p, p, 1.1f);
                break;
            }
        }
        qzero(p);
        *(u8 **)(p + 0x70) = query.hit;
        if (query.hit != 0) {
            *(f32 *)(p + 0x74) = *(f32 *)(query.hit + 0x10);
            *(f32 *)(p + 0x78) = *(f32 *)(query.hit + 0x14);
            *(f32 *)(p + 0x7C) = *(f32 *)(query.hit + 0x18);
        }
        c = func_L01_004CB018(query.surface);
        if (c == collision) {
            *(f32 *)(p + 8) = -0.025f;
            m[0x20] = 7;
            if (query.surface == 0) {
                u8 *effect;
                func_L01_004C67A0(D_001E1090_sda, D_L01_001E1098[0], 1, *(f32 *)(m + 0x10), *(f32 *)(m + 0x14), 0.5f, -0.35f);
                effect = func_L01_003016B0(m + 0x10, 3, 2.0f, 1.025f);
                if (effect != 0) {
                    effect[0x23] = 0x70;
                }
            }
        } else if (c == 1) {
            m[0x20] = 8;
        } else {
            *(s8 *)(p + 0x4E) = func_L01_004CADE8(D_L01_00276E60, m);
            func_L01_0032CA80();
            if (*(s32 *)(D_L01_00276E60 + 0x100 + *(s8 *)(p + 0x4E) * 4) != 0) {
                m[0x20] = 2;
                func_003A52A0(1, 0, m);
                func_L01_00444F38(m, 1, 0, 0, 0);
            } else {
                m[0x20] = 6;
            }
        }
        func_L01_004C8668(*(s8 *)(p + 0x4F));
        D_L01_00278350[*(s32 *)(p + 0x6C)] = D_L01_001DAFEC;
        if (D_L01_001DAFEC != 0) {
            vec_sub_ab(&delta, m + 0x10, D_L01_001DAFEC + 0x10);
            func_0038D5B0(inverse, D_L01_00278350[*(s32 *)(p + 0x6C)] + 0xC0);
            func_0038D028(&delta, &delta, inverse);
            idx = *(s32 *)(p + 0x6C);
            D_L01_002784E0[idx][0] = delta.x;
            D_L01_002784E0[idx][1] = delta.y;
            D_L01_002784E0[idx][2] = delta.z;
        }
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        break;
    case 2:
        if (6.0f <= func_L01_004395E0(m)) {
            func_L01_00444F38(m, 2, 0, 0, 0);
            m[0x20] = 3;
        }
        break;
    case 3:
        func_L01_0032BF70(m);
        goto check70;
    case 4:
        func_L01_0032C220(m);
        func_L01_0032C390(m);
    check70:
        o = *(u8 **)(p + 0x70);
        if (o != 0 && (o[0x20] == 0xFE || o[0x20] == 0xFD)) {
            *(s32 *)(m + 0x98) = 0;
            *(s8 *)(p + 0x4F) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
            m[0x20] = 1;
            *(s32 *)(p + 0x70) = 0;
        }
        break;
    case 5:
        if (func_L01_004395E0(m) <= 1.21f) {
            func_L01_00444F38(m, 0, 0, 0, 0);
            m[0x20] = 6;
            *(f32 *)(m + 0x48) = 1.0f;
        }
        break;
    case 6:
        if (*(s32 *)(D_L01_00276E60 + 0x100 + *(s8 *)(p + 0x4E) * 4) != 0) {
            m[0x20] = 2;
            func_003A52A0(1, 0, m);
            func_L01_00444F38(m, 1, 0, 0, 0);
            *(s32 *)(p + 0x48) = func_L01_004C80F8(m, 0);
        }
        break;
    case 7:
        func_L01_0032BCB0(m);
        func_L01_0032BDD8(m);
        break;
    case 8:
        func_003A52A0(3, 0, m);
        func_L01_0044BB30(m, m + 0x10, -1, 0.5f, 13.0f);
        m[0x20] = 9;
        *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) | 0x41;
        break;
    case 9:
        if (*(s16 *)(p + 0x66) != 0) {
            break;
        }
        if (*(s32 *)(p + 0x48) != -1) {
            func_L01_004C81A8(*(s32 *)(p + 0x48));
        }
        if (*(s8 *)(p + 0x4E) != -1) {
            func_L01_004CAE60(D_L01_00276E60, *(s8 *)(p + 0x4E));
        }
        func_003C2880(m);
        return;
    default:
        break;
    }
    if (m[0x20] >= 2 && D_L01_00278350[*(s32 *)(p + 0x6C)] != 0) {
        idx = *(s32 *)(p + 0x6C);
        direction.x = D_L01_002784E0[idx][0];
        direction.y = D_L01_002784E0[idx][1];
        direction.z = D_L01_002784E0[idx][2];
        direction.w = 0.0f;
        func_0038D000(&direction, &direction, D_L01_00278350[*(s32 *)(p + 0x6C)] + 0xC0);
        vec_add_ab(m + 0x10, D_L01_00278350[*(s32 *)(p + 0x6C)] + 0x10, &direction);
    }
    if (m[0x20] == 3 || m[0x20] == 4) {
        func_L01_0032C5D0(m);
    }
    func_L01_0040E050(p + 0x5C);
    if (func_0038CAD0(p + 0x40) != 0 || D_001A71A4[0] == 0x74) {
        if (m[0x20] != 9) {
            m[0x20] = 8;
        }
    }
    func_L01_0032CB38(m);
    if (m[0x20] == 3 || m[0x20] == 4) {
        func_L01_0032BE90(m);
        if (*(s32 *)(D_L01_00276E60 + 0x100 + *(s8 *)(p + 0x4E) * 4) == 0) {
            func_L01_00444F38(m, 1, 9, 0, 0);
            m[0x20] = 5;
            *(f32 *)(m + 0x48) = -1.0f;
            func_L01_004C81A8(*(s32 *)(p + 0x48));
            *(s32 *)(p + 0x48) = -1;
            *(s16 *)(p + 0x4C) = 1;
            *(vu0_v4 *)(p + 0x20) = *(vu0_v4 *)(p + 0x10);
            *(s32 *)(p + 0x50) = 0;
            *(s32 *)(p + 0x44) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(vu0_v4 *)(p + 0x30) = *(vu0_v4 *)(p + 0x10);
        }
    }
    if (m[0x20] < 8 && *(u8 **)(p + 0x70) != 0) {
        func_L01_0032BEF0(m);
    }
    if (900.0f < func_L01_0040E548(m + 0x10, &D_001A4C60)) {
        func_L01_0032E2B0(m);
    }
    func_L01_00404A10(func_L01_0032CF48, m);
}
