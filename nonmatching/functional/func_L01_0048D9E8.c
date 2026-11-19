/* functional: high. All reads, writes and calls reproduced from asm; dead load of D_001D545C (unused result) omitted; second operand of sprintf in the no-format branch is left in a2 by retail, not passed. */
typedef struct { s32 w0; u8 b4; u8 b5; u8 pad6[2]; s32 w8; s32 wC; u8 b10; u8 pad11[3]; } Row_0048D9E8;
typedef struct { s32 a; s32 b; } Pair_0048D9E8;
extern s32 D_L01_001D8C80;
extern s32 D_L01_001D8C84;
extern char D_L01_001D8C38[];
extern char D_L01_001D8CD0[];
extern char D_L01_001D8CD8[];
extern s32 D_L01_001E0958[];
extern s32 D_L01_001E0954[];
extern Pair_0048D9E8 D_L01_002E9DC0[];
extern void func_L01_0048D9B0(void);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00516FD8(s32, char *);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_005170B8(s32, s32);
extern s32 func_003BB148(s32);

void func_L01_0048D9E8(void) {
    s32 i = 0;
    s32 n;
    s32 cur;
    s32 off;
    s32 id;
    s32 a6;
    s32 b;
    s32 ta;
    s32 tb;
    Row_0048D9E8 *row;
    char *s;

    func_L01_0048D9B0();
    n = 4;
    cur = D_L01_001D8C7C;
    if (D_L01_001E0958[0] == 1 || D_L01_001E0958[0] == 3) {
        cur = cur - 1;
    }
    func_L01_00516D60(0x160003, 0);
    func_L01_00516D60(0x160006, 0);
    func_L01_00516D60(0x160007, 0);
    if (D_L01_001E0958[0] == 0) {
        func_L01_00516FD8(0x160007, D_L01_001D8CD0);
    }
    if (D_L01_001D8C30 >= 0 && D_L01_001D8C30 < 2) {
        func_L01_00516D60(0x160007, 0);
    }
    off = cur * 0x14;
    id = 0x160011;
    do {
        if (cur >= 0 && cur < D_L01_001D8C78) {
            func_L01_00516AA0(id, 1, 1);
            a6 = 0;
            if ((u32)D_L01_001D8C78 >= 2) {
                if (D_L01_001D8C78 == 2) {
                    a6 = (i == 0) ? 1 : 0;
                }
            }
            if (D_L01_001D8C78 >= 3) {
                if (!(1 < i)) {
                    a6 = 1;
                }
            }
            func_L01_00516AA0(i + 0x160016, 1, a6);
            row = (Row_0048D9E8 *)(D_L01_001D8C84 + off);
            func_L01_00516FD8(id, func_00381FF0(row->w0));
            row = (Row_0048D9E8 *)(D_L01_001D8C84 + off);
            if (row->w8 == 0x8D4) {
                func_L01_005170B8(id, 0x80808080);
            } else if (row->b5 == 1) {
                func_L01_005170B8(id, 0x8066CCFF);
            } else {
                func_L01_005170B8(id, 0x666690CC);
            }
            if (i == D_L01_001D8C80 && D_L01_001E0958[0] == 0) {
                row = (Row_0048D9E8 *)(D_L01_001D8C84 + off);
                func_L01_00516FD8(0x160006, func_00381FF0(row->w0));
                func_L01_00516AA0(0x160006, 1, 1);
                row = (Row_0048D9E8 *)(D_L01_001D8C84 + off);
                func_L01_00516FD8(0x160003, func_00381FF0(row->w8));
                func_L01_00516AA0(0x160003, 1, 1);
                row = (Row_0048D9E8 *)(D_L01_001D8C84 + off);
                func_L01_00517190(0x160010, func_003BB148(row->b10));
                func_L01_00516D60(0x160010, 1);
                if (D_L01_001D8C30 >= 3 || D_L01_001D8C30 < 0) {
                    ((void (*)(char *, char *))func_0011B2E8)(D_L01_001D8C38, D_L01_001D8CD0);
                } else {
                    row = (Row_0048D9E8 *)(D_L01_001D8C84 + off);
                    b = row->b10;
                    if (b > 0) {
                        tb = D_L01_002E9DC0[b % 0x3C].b;
                    } else {
                        tb = D_L01_002E9DC0[1].b;
                    }
                    row = (Row_0048D9E8 *)(D_L01_001D8C84 + off);
                    b = row->b10;
                    if (b > 0) {
                        ta = D_L01_002E9DC0[b % 0x3C].a;
                    } else {
                        ta = D_L01_002E9DC0[1].a;
                    }
                    if (tb < 0 || ta < 0) {
                        ((void (*)(char *, char *))func_0011B2E8)(D_L01_001D8C38, D_L01_001D8CD0);
                    } else {
                        char *s1 = func_00381FF0(ta);
                        char *s2 = func_00381FF0(tb);
                        ((void (*)(char *, char *, ...))func_0011B2E8)(D_L01_001D8C38, D_L01_001D8CD8, s1, s2);
                    }
                }
                func_L01_00516D60(0x160007, 1);
                func_L01_00516FD8(0x160007, D_L01_001D8C38);
                D_L01_001E0954[0] = D_L01_001E0954[0] - 1;
                if (D_L01_001E0954[0] <= 0) {
                    D_L01_001E0954[0] = 0;
                    row = (Row_0048D9E8 *)(D_L01_001D8C84 + off);
                    func_L01_00517190(0x160004, row->wC);
                    func_L01_00516AA0(0x160004, 1, 1);
                }
            }
        } else {
            func_L01_00516AA0(id, 1, 0);
            func_L01_00516AA0(i + 0x160016, 1, 0);
        }
        if (D_L01_001D8C78 == 0) {
            if (i == 1) {
                func_L01_00516FD8(0x160012, func_00381FF0(0x15C7));
                func_L01_00516AA0(0x160012, 1, 1);
                func_L01_00516AA0(0x160017, 1, 1);
            }
        }
        id++;
        i++;
        off += 0x14;
        n--;
        cur++;
    } while (n > 0);
}
