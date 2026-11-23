/* functional: medium. Help/hint box draw per state of D_L01_002E5F30: states 1/3/7 draw the opening/closing frame and a quad; 4-6 draw the box with the row text via func_0038FA18; reads the row id at +0xE (pad in HelpRow_0041A9A0). Uses the context's Help_0041A9A0/TextBox_0041A9A0 types. */
extern s32 D_001D6520[];

extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_0038FA18(u16 *, long, char *, s32, unsigned long, f32, f32);
extern void func_L01_0041B600(void);

void func_L01_0041B608(void) {
    Help_0041A9A0 *s = &D_L01_002E5F30;
    u8 *e;
    u8 *tab;
    TextBox_0041A9A0 pk;
    s32 st, t, w, h, c, a, b, flag, off, id;
    long str;
    s32 x0, x1, y0, y1;

    (*(s32 *)(s->cue + 8)) = (*(s32 *)(s->cue + 8)) - 1;
    if ((*(s32 *)(s->cue + 8)) < 0) {
        (*(s32 *)(s->cue + 8)) = 0;
    }
    if ((*(s32 *)(s->cue + 8)) == 0) {
        (*(s32 *)(s->cue + 4)) = 0;
    }
    st = s->state;
    if (st == 0) {
        return;
    }
    if (s->ready == 0) {
        return;
    }
    if (*(u16 *)((u8 *)D_00143950 + 4) == 0) {
        return;
    }
    if ((u32)(st - 1) >= 7) {
        return;
    }
    switch (st) {
    case 1:
        if (((u8 *)D_00143950)[5] == 0) {
            func_L01_0041B600();
            return;
        }
        s->close_frames = 8;
        s->open_frames = 8;
        func_0038C3B0(s->top - 8 + (*(s32 *)(s->cue + 4)), s->top + 8 + (*(s32 *)(s->cue + 4)), s->x10 - 8, s->x10 + 8, 0x60, 0x600E5092);
        func_L01_00436020(0x33, 0x332299DE, (f32)(s->top - s->close_frames + (*(s32 *)(s->cue + 4))), (f32)(s->top + s->close_frames + (*(s32 *)(s->cue + 4))),
                          (f32)(s->x10 - s->open_frames), (f32)(s->x10 + s->open_frames));
        return;
    case 2:
        func_L01_0041B600();
        return;
    case 3:
        if (((u8 *)D_00143950)[5] == 0) {
            func_L01_0041B600();
            return;
        }
        t = s->timer;
        if (!(t < 9)) {
            t = 8;
        }
        if (!(-1 < t)) {
            t = 0;
        }
        a = (s->half_height - 0x20) * t;
        b = (s->half_width - 0x20) * t;
        w = (a >= 0 ? a : a + 7) >> 3;
        w = w + 0x20;
        h = (b >= 0 ? b : b + 7) >> 3;
        h = h + 0x20;
        s->open_frames = h;
        s->close_frames = w;
        func_0038C3B0(s->top - w + (*(s32 *)(s->cue + 4)), s->top + w + (*(s32 *)(s->cue + 4)), s->x10 - h, s->x10 + h, 0x60, 0x600E5092);
        func_L01_00436020(0x33, 0x332299DE, (f32)(s->top - s->close_frames + (*(s32 *)(s->cue + 4))), (f32)(s->top + s->close_frames + (*(s32 *)(s->cue + 4))),
                          (f32)(s->x10 - s->open_frames), (f32)(s->x10 + s->open_frames));
        return;
    case 4:
    case 5:
    case 6:
        if (((u8 *)D_00143950)[5] == 0) {
            func_L01_0041B600();
            return;
        }
        off = 0;
        tab = (u8 *)D_L01_001DFCC0;
        e = tab + (s->index << 4);
        id = *(s16 *)(e + 0xE);
        flag = 0;
        if (id == 0x150E || id == 0x1DC || id == 0xB0E || id == 0x166A || id == 0x1736) {
            flag = 1;
        }
        if (flag != 0) {
            off = 0xA;
            if (s->half_height + 0xA < 0x22) {
                off = 2 - (s->half_height - 0x20);
            }
            s->half_width = 0xD4;
        }
        s->close_frames = s->half_height;
        s->open_frames = s->half_width;
        func_0038C3B0(s->top - s->half_height + (*(s32 *)(s->cue + 4)) - off, s->top + s->half_height + (*(s32 *)(s->cue + 4)) + off, s->x10 - s->half_width, s->x10 + s->half_width,
                      0x60, 0x600E5092);
        func_L01_00436020(0x33, 0x332299DE, (f32)(s->top - s->close_frames + (*(s32 *)(s->cue + 4)) - off),
                          (f32)(s->top + s->close_frames + (*(s32 *)(s->cue + 4)) + off), (f32)(s->x10 - s->open_frames), (f32)(s->x10 + s->open_frames));
        e = (u8 *)D_L01_001DFCC0 + (s->index << 4);
        str = *(s32 *)e;
        if (*(s16 *)(e + 0xE) > 0) {
            func_003910C0(&pk, (*(s32 *)(s->cue + 4)) + 0xF0, (*(s32 *)(s->cue + 4)) + 0x1E0, 0x70, 0x1D4, 0x70, s->top + (*(s32 *)(s->cue + 4)), 0x10, 2);
        } else {
            func_003910C0(&pk, (*(s32 *)(s->cue + 4)) + 0xF0, (*(s32 *)(s->cue + 4)) + 0x1E0, 0x2C, 0x1D4, 0x100, s->top + (*(s32 *)(s->cue + 4)), 0x10, 3);
        }
        pk.flags = pk.flags | 0x20;
        pk.f1A = 2;
        pk.f18 = 2;
        e = (u8 *)D_L01_001DFCC0 + (s->index << 4);
        id = *(s16 *)(e + 0xE);
        if (id > 0) {
            if (id == 0x150E || id == 0x1DC || id == 0xB0E || id == 0x166A || id == 0x1736) {
                s32 sid;
                if (id == 0x150E) {
                    sid = 0x5D;
                } else if (id == 0x1DC) {
                    sid = 0x5C;
                } else if (id == 0xB0E) {
                    sid = 0x61;
                } else if (id == 0x166A) {
                    sid = 0x62;
                } else {
                    sid = 0x5E;
                }
                func_0038B4D0(0x32, s->top - 0x1E + (*(s32 *)(s->cue + 4)), 0x38, 0x3D, 0, 0, 0x40, 0x40, (long)(s32)0x80808080,
                              func_00389598(sid));
            } else {
                func_003910C0(&pk, (*(s32 *)(s->cue + 4)) + 0xF0, (*(s32 *)(s->cue + 4)) + 0x1E0, 0x2C, 0x1D4, 0x100, s->top + (*(s32 *)(s->cue + 4)), 0x10, 3);
                pk.flags = pk.flags | 0x20;
                pk.f1A = 2;
                pk.f18 = 2;
            }
        }
        D_001D6520[0] = (s->state == 4) ? 1 : 2;
        func_0038E150(1);
        func_0038FA18((u16 *)&pk, 0x8066CCFFL, (char *)str, -1, 0x80000000UL, 1.0f, 1.0f);
        return;
    case 7:
        if (((u8 *)D_00143950)[5] == 0) {
            func_L01_0041B600();
            return;
        }
        t = s->timer;
        if (!(t < 9)) {
            t = 8;
        }
        if (!(-1 < t)) {
            t = 0;
        }
        c = (8 - t) * 12;
        a = (s->close_frames - 8) * t;
        b = (s->open_frames - 8) * t;
        x0 = s->close_frames - ((a >= 0 ? a : a + 7) >> 3);
        y0 = s->open_frames - ((b >= 0 ? b : b + 7) >> 3);
        func_0038C3B0(s->top - x0 + (*(s32 *)(s->cue + 4)), s->top + x0 + (*(s32 *)(s->cue + 4)), s->x10 - y0, s->x10 + y0, c, 0x600E5092);
        func_L01_00436020(c, 0x332299DE, (f32)(s->top - x0 + (*(s32 *)(s->cue + 4))), (f32)(s->top + x0 + (*(s32 *)(s->cue + 4))),
                          (f32)(s->x10 - y0), (f32)(s->x10 + y0));
        return;
    }
}
