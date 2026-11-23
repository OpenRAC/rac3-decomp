#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;

/* localdecomp:start func_L01_003104B8 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Ent_003104B8;
extern Ent_003104B8 *D_L01_001E172C;
extern s32 func_0038CAD0(void *);

void func_L01_003104B8(s32 key) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (D_L01_001E172C[i].b == key && func_0038CAD0(&D_L01_001E172C[i].c)) {
            D_L01_001E172C[i].b = 0;
            D_L01_001E172C[i].a = 0;
        }
    }
}
/* localdecomp:end func_L01_003104B8 */
