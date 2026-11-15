#include "common.h"

/* localdecomp:start func_L39_0069E1A8 */
void func_L39_0069E1A8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x2C8) = arg1;
}
/* localdecomp:end func_L39_0069E1A8 */

/* localdecomp:start func_L39_0069E1B0 */
extern char D_L39_00248340[];
extern char D_L39_00248348[];
extern char D_L39_00248350[];
extern char D_L39_00248358[];
extern f32 D_L39_004B03A0[]; /* 12 x {x, y, z} */
extern char *func_00381FF0(s32 id);
extern int func_00120048(char *, char *, ...);

typedef struct V_0069E1B0 V_0069E1B0;
typedef struct O_0069E1B0 {
    u8 pad[0x60];
    V_0069E1B0 *vt;
} O_0069E1B0;
struct V_0069E1B0 {
    u8 pad[0x1C];
    void (*f1C)(O_0069E1B0 *, s32, s32);
    u8 pad20[4];
    void (*f24)(O_0069E1B0 *, char *);
    void (*f28)(O_0069E1B0 *, f32, f32);
};

void func_L39_0069E1B0(u8 *p) {
    char buf0[0x20];
    char buf1[0x20];
    char buf2[0x20];
    char **table;
    O_0069E1B0 **objs;
    s32 i;
    f32 *pos;
    f32 *py;


    func_00120048(buf0, D_L39_00248348, func_00381FF0(0x12C));
    func_00120048(buf1, D_L39_00248350, func_00381FF0(0x181D));
    func_00120048(buf2, D_L39_00248358, func_00381FF0(0x1826));
    {
        char *tableA[12] = {
            func_00381FF0(0x180D), buf0, func_00381FF0(0x180A), func_00381FF0(0x1815),
            func_00381FF0(0x8E6), func_00381FF0(0x1810), func_00381FF0(0x1809), func_00381FF0(0x1811),
            func_00381FF0(0x194B), func_00381FF0(0x180E), func_00381FF0(0x181C), D_L39_00248340,
        };
        char *tableB[12] = {
            func_00381FF0(0x1820), buf1, func_00381FF0(0x194B), func_00381FF0(0x1815),
            func_00381FF0(0x8E6), func_00381FF0(0x1822), func_00381FF0(0x181E), func_00381FF0(0x1823),
            func_00381FF0(0x194B), func_00381FF0(0x1820), func_00381FF0(0x1825), buf2,
        };
        char *tableC[12] = {
            func_00381FF0(0x1816), buf1, func_00381FF0(0x194B), func_00381FF0(0x1815),
            func_00381FF0(0x8E6), func_00381FF0(0x1818), func_00381FF0(0x181B), func_00381FF0(0x1819),
            func_00381FF0(0x194B), func_00381FF0(0x1816), func_00381FF0(0x181C), D_L39_00248340,
        };

        if (*(s32 *)(p + 0x2A8) == 0) {
            table = tableA;
        } else if (*(s32 *)(p + 0x2A8) == 1) {
            table = tableB;
        } else {
            table = tableC;
        }
        objs = (O_0069E1B0 **)(p + 0x12C);
        pos = D_L39_004B03A0;
        for (i = 0; i < 12; i++) {
            char *s = table[i];
            (*objs)->vt->f24(*objs, s);
            py = &pos[i * 3 + 1];
            (*objs)->vt->f28(*objs, py[-1], py[0]);
            (*objs)->vt->f1C(*objs, *(u8 *)s != 0, 0);
            objs++;
        }

    }
}
/* localdecomp:end func_L39_0069E1B0 */

LINKER_REMNANT("asm/levels", func_L39_0069E5B8);
