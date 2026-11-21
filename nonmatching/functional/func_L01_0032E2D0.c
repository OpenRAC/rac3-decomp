/* functional: high. Compiles; all 69 jal targets identical to retail as a multiset (checked by diffing the compiled output). Ported structure from the NTSC-U draft but every callee, constant and global re-read against PAL asm: PAL differences from NTSC: initial h90=150, h90 refill=(rand(180,240)*5+2)/6, state 11 flag 0x0001002100000000 and sound id 0x25, func_L01_004CB018 result compared to the collision code, effect functions renamed. */
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
} Query_0032E2D0;

extern s32 D_L01_001DCE4C;
__asm__(".extern D_L01_001DCE4C, 4");
extern f32 D_001DCEB0_sda;
__asm__(".extern D_001DCEB0_sda, 4");
extern f32 D_001DCEB8_sda;
__asm__(".extern D_001DCEB8_sda, 4");
extern void *D_001E1090_sda;
__asm__(".extern D_001E1090_sda, 4");
extern void *D_L01_001E1098[];
extern u8 D_L01_00278990[];
extern u8 *D_L01_00278350[];
extern f32 D_L01_002784E0[][3];
extern u8 *D_L01_001DAFEC;
extern s32 D_L01_001D673C[], D_L01_001D6740[];
extern u8 *D_L01_001EEA80[];
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
extern s32 func_L01_004C7E70(Query_0032E2D0 *, s32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_L01_004CB018(void *);
extern void func_L01_004C67A0(void *, void *, s32, f32, f32, f32, f32);
extern u8 *func_L01_003016B0(void *, s32, f32, f32);
extern s32 func_L01_004CADE8(void *, void *);
extern void func_L01_0032FB80(void);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_00444F38(void *, s32, s32, s32, s32);
extern void func_L01_004C8668(s32);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_0032F1B8(void *);
extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_0038CB00(void *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0032F4E0(void *);
extern void func_L01_0032F3E0(void *);
extern s32 func_L01_004C80F8(void *, s32);
extern void func_L01_0032EF88(void *);
extern void func_L01_0032F020(void *);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern void func_L01_004C81A8(s32);
extern void func_L01_004CAE60(void *, s32);
extern void func_003C2880(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00409428(void *, void *, void *, void *, void *, s32, s32, s32, u32, u32);
extern void func_00382580(void *, f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_L01_0032EE48(void *, void *, void *, f32);
extern void func_L01_0032F718(void *);
extern void func_L01_0040E050(void *);
extern s32 func_0038CAD0(u8 *);
extern void func_L01_0032F0D8(void *);
extern void func_L01_0032F138(void *);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_L01_0032FBA0(void *);

void func_L01_0032E2D0(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    vu0_v4 old_position, direction, forward, quaternion, axis, rotation[3], delta, inverse[4];
    Query_0032E2D0 query;
    s32 info[2];
    s32 collision, c, idx, n, found;
    f32 angle;
    u8 *o;
    u8 **it;

    switch (m[0x20]) {
    case 0:
        m[0x20] = 1;
        *(s32 *)(p + 0x6C) = D_L01_001DCE4C;
        D_L01_001DCE4C = (D_L01_001DCE4C + 1) % 100;
        *(s16 *)(p + 0x90) = 150;
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
        func_L01_004C7D40(m + 0x10, p, D_001DCEB0_sda * 0.00040000002f);
        query.from = old_position;
        query.to = *(vu0_v4 *)(m + 0x10);
        info[0] = 0;
        info[1] = 0xC5A;
        query.velocity = *(vu0_v4 *)p;
        query.info = info;
        query.radius = 0.13f;
        query.step = D_001DCEB8_sda;
        query.scale = 0.5555556f;
        query.skin = 0.0962f;
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
            *(s8 *)(p + 0x4E) = func_L01_004CADE8(D_L01_00278990, m);
            func_L01_0032FB80();
            if (*(s32 *)(D_L01_00278990 + 0x100 + *(s8 *)(p + 0x4E) * 4) != 0) {
                m[0x20] = 2;
                func_L01_004AAC98(1, 0, m, 0x1367);
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
        if (6.5f <= func_L01_004395E0(m)) {
            func_L01_00444F38(m, 2, 0, 0, 0);
            m[0x20] = 3;
        }
        break;
    case 3:
        func_L01_0032F1B8(m);
        o = *(u8 **)(p + 0x70);
        if (o != 0 && (o[0x20] == 0xFE || o[0x20] == 0xFD)) {
            *(s32 *)(m + 0x98) = 0;
            *(s8 *)(p + 0x4F) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
            m[0x20] = 1;
            *(s32 *)(p + 0x70) = 0;
        }
        if (*(s16 *)(D_001A4BE0 + 0x368) == 0 && D_L01_001D673C[0] == 0 && D_L01_001D6740[0] == 0) {
            if (400.0f < func_L01_0040E570(D_001A4BE0 + 0x80, m + 0x10) && func_0038CB00(p + 0x90) != 0) {
                found = 0;
                n = func_003D4D00(D_001A4BE0 + 0x80, 1, *(void **)(D_001A4BE0 + 0x25C0), 0, 20.0f);
                it = D_L01_001EEA80;
                while (n > 0) {
                    o = *it++;
                    if (o != 0 && *(u8 **)(o + 0x24) != 0 && (*(u8 **)(o + 0x24))[0x46] == 5) {
                        found = 1;
                    }
                    n--;
                }
                if (found != 0) {
                    *(s16 *)(p + 0x90) = (func_00382498(180, 240) * 5 + 2) / 6;
                    func_L01_004450F0(m, 10, -1);
                }
            }
        }
        break;
    case 4:
        func_L01_0032F3E0(m);
        func_L01_0032F4E0(m);
        o = *(u8 **)(p + 0x70);
        if (o != 0 && (o[0x20] == 0xFE || o[0x20] == 0xFD)) {
            *(s32 *)(m + 0x98) = 0;
            *(s8 *)(p + 0x4F) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
            m[0x20] = 1;
            *(s32 *)(p + 0x70) = 0;
        }
        break;
    case 5:
        if (func_L01_004395E0(m) <= 1.0f) {
            func_L01_00444F38(m, 0, 0, 0, 0);
            *(f32 *)(m + 0x48) = 1.0f;
            m[0x20] = 6;
        }
        break;
    case 6:
        if (*(s32 *)(D_L01_00278990 + 0x100 + *(s8 *)(p + 0x4E) * 4) != 0) {
            m[0x20] = 2;
            func_L01_004AAC98(1, 0, m, 0x1367);
            func_L01_00444F38(m, 1, 0, 0, 0);
            *(s32 *)(p + 0x48) = func_L01_004C80F8(m, 0);
        }
        break;
    case 7:
        func_L01_0032EF88(m);
        func_L01_0032F020(m);
        break;
    case 8:
        func_L01_004AAC98(3, 0, m, 0x1367);
        func_L01_0044BB30(m, m + 0x10, -1, 0.5f, 13.0f);
        m[0x20] = 9;
        *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) | 0x41;
        break;
    case 9:
        if (*(s32 *)(p + 0x48) != -1) {
            func_L01_004C81A8(*(s32 *)(p + 0x48));
        }
        if (*(s8 *)(p + 0x4E) != -1) {
            func_L01_004CAE60(D_L01_00278990, *(s8 *)(p + 0x4E));
        }
        func_003C2880(m);
        return;
    case 11:
        if (*(s16 *)(p + 0x9E) == 2) {
            func_L01_004450F0(m, 3, -1);
            break;
        }
        if ((*(unsigned long *)(p + 0x98) & 0xFFFFFFFF00000000UL) == 0x0001002100000000UL) {
            func_003A52A0(5, 0, m);
        }
        func_L01_00409428(m, p + 0x9C, p + 0x9E, p + 0x80, m + 0xF0, 2, 3, 0x25, 0xFF8040, 0x8F1010);
        break;
    case 10:
        func_00382580(&delta, 3.0f, 6.5f);
        vec_add_ab(&delta, &delta, &D_001A4C60);
        if (delta.z < D_001A4C60.z) {
            delta.z = D_001A4C60.z;
        }
        delta.z = func_003C3D30(&delta, 0, 0, 0.5f) + 1.0f;
        if (func_L01_0032EE48(p + 0x80, &delta, m, 10.0f) != 0 &&
            400.0f < func_L01_0040E570(&D_001A4C60, m + 0x10) && func_L01_004CB2D8() == 0) {
            func_L01_004450F0(m, 11, -1);
            func_003A52A0(5, 0, m);
            *(s16 *)(p + 0x9E) = 0;
            *(s16 *)(p + 0x9C) = 0x25;
            break;
        }
        func_L01_004450F0(m, 3, -1);
        break;
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
        func_L01_0032F718(m);
    }
    func_L01_0040E050(p + 0x5C);
    if (func_0038CAD0(p + 0x40) != 0 || D_001A71A4[0] == 0x74) {
        if (m[0x20] != 9) {
            m[0x20] = 8;
        }
    }
    if (m[0x20] == 3 || m[0x20] == 4) {
        func_L01_0032F0D8(m);
        if (*(s32 *)(D_L01_00278990 + 0x100 + *(s8 *)(p + 0x4E) * 4) == 0) {
            func_L01_00444F38(m, 1, 9, 0, 0);
            m[0x20] = 5;
            *(f32 *)(m + 0x48) = -1.0f;
            func_L01_004C81A8(*(s32 *)(p + 0x48));
            *(s32 *)(p + 0x48) = -1;
            *(s16 *)(p + 0x4C) = 1;
            *(vu0_v4 *)(p + 0x20) = *(vu0_v4 *)(p + 0x10);
            *(s32 *)(p + 0x50) = 0;
            *(s32 *)(p + 0x44) = 0;
            *(s32 *)(p + 0x64) = 0;
            *(vu0_v4 *)(p + 0x30) = *(vu0_v4 *)(p + 0x10);
        }
    }
    if (m[0x20] < 8 && *(u8 **)(p + 0x70) != 0) {
        if (*(s32 *)(*(u8 **)(p + 0x70) + 0x24) == 0) {
            *(s32 *)(p + 0x70) = 0;
        } else {
            func_L01_0032F138(m);
        }
    }
    func_L01_00404A10(func_L01_0032FBA0, m);
}
