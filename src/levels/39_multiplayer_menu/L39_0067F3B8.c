#include "common.h"

typedef struct S_0067EF00 {
    s32 f0;
    s32 f4;
    s32 f8;
} S_0067EF00;

/* declared by functions of L39_0067EF00.c, which this file was cut from */
extern s32 func_00120884(char *);
extern void func_0011D534(void *, s32, s32);
extern char *func_001206F4(void *, void *);
extern void func_L39_0067F3B8(s32, char *);

/* localdecomp:start func_L39_0067F3B8 */
extern s32 D_L39_00241470;
extern f32 D_L39_00245C38;
extern s32 D_L39_0024D768;
extern s32 D_L39_0024D76C;
extern char D_L39_003CE740[128][0x70];
extern s32 D_L39_003D1F40[128];
extern void func_0038E150(s32);
extern s32 func_L01_0048AA30(char *, s32, f32);
extern void func_00120D28(char *, char *, s32);

void func_L39_0067F3B8(s32 owner, char *text) {
    char buf[10][0x70];
    s32 i;
    char *line;
    s32 len;
    s32 total;
    s32 k;
    s32 space;
    s32 saved;
    s32 maxw;
    s32 n;
    s32 lines;

    if (text == 0) {
        return;
    }
    n = 1;
    len = func_00120884(text);
    total = 0;
    saved = D_L39_00241470;
    k = 1;
    lines = 0;
    space = -1;
    func_0038E150(1);
    func_L01_0048AA30(text, len, 1.0f);
    maxw = D_L39_00245C38 * 0.38f;
    if (len > 0) {
        line = buf[0];
        do {
            n = lines + 1;
            if (((u8 *)text)[k - 1] == ' ') {
                space = k;
            }
            func_0011D534(line, 0, 0x70);
            func_00120D28(line, text, k);
            if (func_L01_0048AA30(line, len, 1.0f) >= maxw) {
                if (space != -1) {
                    k = space;
                }
                func_0011D534(line, 0, 0x70);
                total += k;
                space = -1;
                func_00120D28(line, text, k);
                text += k;
                line += 0x70;
                lines = n;
                k = 1;
            } else {
                k++;
            }
        } while (total + k <= len);
    }
    func_0038E150(saved);
    if (D_L39_0024D768 + n >= 0x80) {
        for (i = 0; i < 0x80 - n; i++) {
            func_00120D28(D_L39_003CE740[i], D_L39_003CE740[i + n], 0x6F);
            D_L39_003CE740[i][0x6F] = 0;
        }
        D_L39_0024D768 -= n;
    }
    for (k = 0; k < n; k++) {
        D_L39_003D1F40[D_L39_0024D768] = owner;
        func_001206F4(D_L39_003CE740[D_L39_0024D768], buf[k]);
        D_L39_003CE740[D_L39_0024D768][0x6F] = 0;
        D_L39_0024D768++;
        D_L39_0024D76C++;
    }
}
/* localdecomp:end func_L39_0067F3B8 */
