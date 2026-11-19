/* functional: medium-high. Multiplayer lobby/results panel refresh: loads title strings, picks the current game slot, sets the header (player name or game title), formats the elapsed time (m:ss), the progress bar level from D_L39_00240400, then fills up to 8 rows (name, score diff, counts, and per-mode columns: mode 0 shows a percentage of the total, mode 1 two byte stats, mode 2 blanks). Layout of D_001FD7E8 read by raw offsets (0x120 ids, 0x140/0x1B8 s16 scores, 0x160/0x170/0x178 bytes, 0x180/0x1A0 floats, 0x1A8 current, 0x808/0x80C/0x814/0x818/0x828 words). The percent divide has no zero guard, as retail (the PS2 gives max float; the host must not produce NaN: guard or clamp when this is wired into the port). func_005C1A60 args (mode,mode,0x400) unknown purpose. Not byte exact (frame and register allocation). */
__asm__(".extern D_L39_00241640, 4");
__asm__(".extern D_L39_00240400, 16");
extern u8 *D_L39_00241640;
extern s32 D_L39_00240400;
extern s32 D_001A5CD0[];
extern u8 D_001A58C7;
extern u8 D_001FD7E8[];
extern u8 D_L39_002488C0[];
extern u8 D_L39_002488D8[];
extern u8 D_L39_002488E0[];
extern u8 D_L39_002488F0[];
extern u8 D_L39_002488F8[];
extern u8 D_L39_00248900[];
extern s32 func_00120048(void *, void *, ...);
extern s32 func_00120884(void *);
extern void *func_001206F4(void *, void *);
extern s32 func_001321C8(f32);
extern void func_L39_00689BD8(void *, void *);
extern void func_L39_00689DB8(void *, void *);
extern void func_L39_006A7178(void *);
extern void func_L39_005C1A60(s32, s32, s32);
extern void func_L39_006CEA18(void *, s32);
extern u8 *func_L39_0066C7D8(s32);
extern s32 func_L39_0066C788(s32);
extern u8 *func_L39_006A8E38(void *, s32);
extern u8 *func_L39_006D31B8(void *, s32);

typedef void (*VfnP)(void *, void *);
typedef void (*VfnI)(void *, s32);
typedef void (*VfnII)(void *, s32, s32);
typedef void (*VfnFF)(void *, f32, f32);

#define OBJ(self, off) (*(u8 **)((self) + 0x110 + (off)))
#define VCALL_P(o, slot, a) ((*(VfnP *)(*(u8 **)((o) + 0x60) + (slot)))((o), (a)))

void func_L39_006A83B8(u8 *self) {
    u8 buf[0x20];
    u8 line[0x20];
    u8 *D = D_001FD7E8;
    s32 *g = D_001A5CD0;
    s32 cur;
    s32 mode;
    s32 sel;
    s32 idx;
    s32 i;
    s32 j;
    s32 t;
    s32 mins;
    s32 secs;
    s32 v;
    s32 slot;
    s32 other;
    f32 sum;
    f32 pct;
    f32 ftmp;
    u8 *o;
    u8 *name;
    u8 *r;
    u8 *txt;
    u8 *list;

    func_L39_00689BD8(self, func_00381FF0(0x11F5));
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_006A7178(self);
    *(s32 *)(self + 0x488) = 0;
    *(s32 *)(self + 0x484) = *(s32 *)(D + 0x80C);
    sel = *(s32 *)(D + 0x808);

    /* find the index of the current game in the 8-entry table at D_L39_00241640 + 0xE0 */
    idx = -1;
    if (*(s16 *)(D_L39_00241640 + 0xE0) == g[2]) {
        idx = 0;
    } else {
        for (i = 1; i < 8; i++) {
            if (*(s16 *)(D_L39_00241640 + 0xE0 + i * 2) == g[2]) {
                idx = i;
                break;
            }
        }
    }
    cur = *(s32 *)(D + 0x1A8);
    if (cur == -1) {
        func_L39_005C1A60(0, 0, 0x400);
    } else if (idx < 0) {
        func_L39_005C1A60(3, 3, 0x400);
    } else if (*(s32 *)(D + 0x120 + idx * 4) != cur) {
        func_L39_005C1A60(3, 3, 0x400);
    } else {
        func_L39_005C1A60(2, 2, 0x400);
    }
    list = self + 0x450;

    if (g[0x174 / 4] == 0) {
        func_L39_006CEA18(*(u8 **)((u8 *)D_L39_0024D760 + 0x38), 0);
        func_001206F4(buf, (u8 *)g + 0xBE);
        i = 0x11;
        if (buf[0x11] == 0x20) {
            i = 0x10;
            while (buf[i] == 0x20) {
                i--;
            }
        }
        buf[i + 1] = 0;
        o = *(u8 **)(self + 0x110);
        VCALL_P(o, 0xB8, buf);
    }

    cur = *(s32 *)(D + 0x1A8);
    if (cur == -1) {
        func_001206F4(line, func_00381FF0(0xF3A));
        o = *(u8 **)(self + 0x114);
    } else {
        if (*(s32 *)(self + 0x484) == 2 && *(s32 *)(D + 0x828) == 0) {
            func_001206F4(buf, self + cur * 16 + 0x2A8);
            v = 0x1334;
        } else if (sel == 2) {
            r = 0;
            for (i = 0; i < 8; i++) {
                if (*(s32 *)(D + 0x120 + i * 4) == cur) {
                    r = func_L39_006A8E38(self, i);
                    break;
                }
            }
            if (r != 0 && *(s32 *)(r + 0x24) >= 0) {
                u8 *p = func_L39_006D31B8(*(u8 **)((u8 *)D_L39_0024D760 + 0x38), *(s32 *)(D_L39_00241640 + 0x150 + i * 4));
                if (p != 0) {
                    p = p + 0x20;
                } else {
                    p = func_L39_0066C7D8(*(s32 *)(D + 0x1A8));
                }
                func_001206F4(buf, p);
            } else {
                func_001206F4(buf, func_L39_0066C7D8(*(s32 *)(D + 0x1A8)));
            }
            v = 0x1334;
        } else {
            func_001206F4(buf, func_L39_0066C7D8(*(s32 *)(D + 0x1A8)));
            v = 0x1334;
        }
        func_00120048(line, D_L39_002488D8, buf, func_00381FF0(v));
        o = *(u8 **)(self + 0x114);
    }
    VCALL_P(o, 0x24, line);

    t = *(s32 *)(D + 0x814);
    mins = t / 60000;
    secs = (t % 60000) / 1000;
    func_00120048(line, D_L39_002488E0, func_00381FF0(0x1100), mins,
                  secs < 10 ? D_L39_002488F0 : D_L39_002488C0, secs);
    o = *(u8 **)(self + 0x118);
    VCALL_P(o, 0xB8, line);

    sum = 0.0f;
    v = D_L39_00240400;
    if (v >= 50) {
        v -= 10;
    }
    if (v >= 50) {
        v = 49;
    }
    if (!(39 < v)) {
        v = 40;
    }
    o = *(u8 **)(self + 0x120);
    (*(VfnI *)(*(u8 **)(o + 0x60) + 0xDC))(o, v + 7);

    if (*(s32 *)(self + 0x484) == 0) {
        for (i = 0; i < 8; i++) {
            if (*(s32 *)(D + 0x120 + i * 4) == *(s32 *)(D + 0x1A8)) {
                sum += *(f32 *)(D + 0x180 + i * 4);
            }
        }
        if (sum <= 0.0f) {
            sum = 1.0f;
        }
        if (*(s32 *)(D + 0x818) == 1) {
            ftmp = *(f32 *)(D + 0x1A0 + *(s32 *)(D + 0x1A8) * 4);
            if (sum + 5.0f < ftmp) {
                sum = ftmp;
            } else {
                sum = sum + 5.0f;
            }
        }
    }

    o = *(u8 **)(self + 0x164);
    VCALL_P(o, 0xB8, func_00381FF0(0x1332));
    o = *(u8 **)(self + 0x168);
    VCALL_P(o, 0xB8, func_00381FF0(0x1336));
    o = *(u8 **)(self + 0x16C);
    VCALL_P(o, 0xB8, func_00381FF0(0x1337));
    o = *(u8 **)(self + 0x174);
    (*(VfnFF *)(*(u8 **)(o + 0x60) + 0x38))(o, 1.0f, 1.0f);
    mode = *(s32 *)(self + 0x484);
    if (mode == 1) {
        o = *(u8 **)(self + 0x170);
        VCALL_P(o, 0xB8, func_00381FF0(0x1B73));
        o = *(u8 **)(self + 0x174);
        VCALL_P(o, 0xB8, func_00381FF0(0x1765));
    } else if (mode == 2) {
        o = *(u8 **)(self + 0x170);
        VCALL_P(o, 0xB8, D_L39_002488C0);
        o = *(u8 **)(self + 0x174);
        VCALL_P(o, 0xB8, D_L39_002488C0);
    } else if (mode == 0) {
        o = *(u8 **)(self + 0x170);
        VCALL_P(o, 0xB8, func_00381FF0(0xF37));
        o = *(u8 **)(self + 0x174);
        VCALL_P(o, 0xB8, func_00381FF0(0x133D));
        if (D_001A58C7 == 2) {
            o = *(u8 **)(self + 0x174);
            (*(VfnFF *)(*(u8 **)(o + 0x60) + 0x38))(o, 0.725f, 1.0f);
        } else if (D_001A58C7 == 5) {
            o = *(u8 **)(self + 0x174);
            (*(VfnFF *)(*(u8 **)(o + 0x60) + 0x38))(o, 0.7f, 0.9f);
        }
    }

    for (i = 0; i < 8; i++) {
        slot = ((s32 *)list)[i];
        name = self + slot * 16 + 0x2A8;
        if (func_00120884(name) == 0) {
            continue;
        }
        o = OBJ(self, 0x14 + i * 4);
        (*(VfnII *)(*(u8 **)(o + 0x60) + 0x1C))(o, 1, 0);
        o = OBJ(self, (i + 0xD) * 4);
        (*(VfnII *)(*(u8 **)(o + 0x60) + 0x1C))(o, 1, 0);
        v = func_L39_0066C788(*(s32 *)(D + 0x120 + slot * 4));
        (*(VfnI *)(*(u8 **)(o + 0x60) + 0x50))(o, v);
        o = OBJ(self, 0x68 + i * 0x14);
        VCALL_P(o, 0xB8, name);
        func_00120048(line, D_L39_002488F8,
                      *(s16 *)(D + 0x140 + slot * 4) - *(s16 *)(D + 0x1B8 + slot * 2));
        o = OBJ(self, 0x6C + i * 0x14);
        VCALL_P(o, 0xB8, line);
        func_00120048(line, D_L39_002488F8, *(s16 *)(D + 0x142 + slot * 4));
        o = OBJ(self, 0x70 + i * 0x14);
        VCALL_P(o, 0xB8, line);
        mode = *(s32 *)(self + 0x484);
        if (mode == 1) {
            func_00120048(line, D_L39_002488F8, D[0x170 + slot]);
            o = OBJ(self, 0x74 + i * 0x14);
            VCALL_P(o, 0xB8, line);
            func_00120048(line, D_L39_002488F8, D[0x178 + slot]);
            o = OBJ(self, 0x78 + i * 0x14);
            VCALL_P(o, 0xB8, line);
        } else if (mode == 2) {
            o = OBJ(self, 0x74 + i * 0x14);
            VCALL_P(o, 0xB8, D_L39_002488C0);
            o = OBJ(self, 0x78 + i * 0x14);
            VCALL_P(o, 0xB8, D_L39_002488C0);
        } else if (mode == 0) {
            func_00120048(line, D_L39_002488F8, D[0x160 + slot]);
            o = OBJ(self, 0x74 + i * 0x14);
            VCALL_P(o, 0xB8, line);
            other = *(s32 *)(D + 0x120 + slot * 4);
            if (other == *(s32 *)(D + 0x1A8)) {
                pct = *(f32 *)(D + 0x180 + slot * 4) / sum * 100.0f;
            } else {
                pct = *(f32 *)(D + 0x180 + slot * 4) / *(f32 *)(D + 0x1A0 + other * 4) * 100.0f;
            }
            if (100.0f < pct) {
                pct = 100.0f;
            }
            if (pct < 0.0f) {
                pct = 0.0f;
            }
            func_00120048(line, D_L39_00248900, func_001321C8(pct));
            o = OBJ(self, 0x78 + i * 0x14);
            VCALL_P(o, 0xB8, line);
        }
    }
}
