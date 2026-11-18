#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_00302048 */
extern char D_L01_0026EC90_00302048[];
extern char D_L01_0026ED10[];
__asm__(".extern D_L01_001DC460, 4");
extern f32 D_L01_001DC460;
__asm__(".extern D_L01_001DC488, 4");
extern f32 D_L01_001DC488;
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);

void func_L01_00302048(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        char *entry = D_L01_0026EC90_00302048 + i * 16;
        func_0038D890(entry, entry, D_L01_0026ED10 + i * 16, D_L01_001DC460);
        func_0038CF68(entry, entry, D_L01_001DC488);
    }
}
/* localdecomp:end func_L01_00302048 */
