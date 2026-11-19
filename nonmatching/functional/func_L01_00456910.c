/* functional: high. Straight translation of the PAL assembly (the 83-diff near miss's structure, names re-checked): count 0 / 1 / many branches, same call arguments, 9999999.0f initial distance. Checked with --no-context: the file context declares D_001A71A0 with another element type (the lead aligns the extern on landing). */
extern char *D_L01_001DFC4C;
extern u8 *D_L01_001DFC48;
extern s32 D_L01_001DFB40;
extern u8 *D_001A71A0[];
extern u8 D_001A4BE0[];
extern void func_L01_00456270(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L01_004566F8(void *, void *, s32, s32, s32, s32, f32);

u8 *func_L01_00456910(u8 *source, s32 index, s32 *out, s32 team, s32 c, s32 d, s32 check, s32 g, f32 scale) {
    u8 *rec;
    s32 count;
    u8 *item;
    u8 *best;
    u8 *pos;
    u8 *other;
    f32 dist;
    f32 v;
    s32 t;

    if (index < 0) {
        return 0;
    }
    if (index >= *(s32 *)D_L01_001DFC4C || D_L01_001DFB40 < 2) {
        return 0;
    }
    pos = 0;
    if (check != 0) {
        pos = source + 0x10;
    }
    func_L01_00456270(index);
    rec = D_L01_001DFC48 + index * 0xE0;
    count = rec[4];
    if (count == 0) {
        return 0;
    }
    if (count == 1) {
        other = *(u8 **)rec;
        if (other == 0) {
            return 0;
        }
        other = other + 0x10;
        if (check == 0) {
            other = 0;
        }
        *out = rec[5];
        if (team == 0) {
            if (check != 0) {
                if (func_003D3CB0(pos, other, 2, source, 0) == 0) {
                    return 0;
                }
            }
            return *(u8 **)rec;
        }
        if (check != 0) {
            if (func_003D3CB0(pos, other, 2, source, 0) == 0) {
                return 0;
            }
        }
        if (*out == team) {
            return *(u8 **)rec;
        }
        if (*(u8 **)rec == D_001A71A0[0]) {
            return *(u8 **)rec;
        }
        return 0;
    }
    dist = 9999999.0f;
    best = 0;
    do {
        item = *(u8 **)rec;
        if (item != 0) {
            v = func_L01_004566F8(source, item, c, d, check, g, scale);
            if (v < dist && item != source) {
                t = rec[5];
                if (team == 0) {
                    dist = v;
                    best = *(u8 **)rec;
                    *out = t;
                } else if (t == team || item == *(u8 **)(D_001A4BE0 + 0x25C0)) {
                    best = *(u8 **)rec;
                    dist = v;
                    *out = t;
                }
            }
        }
        count--;
        rec += 8;
    } while (count != 0);
    return best;
}
