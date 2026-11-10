#include "common.h"

typedef struct { int a, b, c; } T;

/* localdecomp:start func_L39_0067C948 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
typedef struct { u8 pad[0xE8]; void (*m)(void *); } V_0067C948;
typedef struct { u8 pad[0x60]; V_0067C948 *vt; } O_0067C948;
extern O_0067C948 *D_L39_00247914 __attribute__((section(".data")));
extern void *D_001DC204_sda;
void func_001959F8(void);
void func_L39_0067EC30(void);
void func_L01_00478898(void);
void func_003B3088(s32);
void func_L39_005F1718(void);
void func_L39_006D8B88(void *);

void func_L39_0067C948(void) {
    O_0067C948 *obj;
    func_001959F8();
    func_L39_0067EC30();
    func_L01_00478898();
    func_003B3088(0);
    func_L39_005F1718();
    if (D_L39_0024D760 != 0) {
        func_L39_006D8B88(D_L39_0024D760);
        obj = D_L39_00247914;
    } else {
        obj = D_001DC204_sda;
    }
    if (obj != 0) {
        obj->vt->m(obj);
    }
}
/* localdecomp:end func_L39_0067C948 */

INCLUDE_ASM("asm/levels", func_L39_0067C9C0);

INCLUDE_ASM("asm/levels", func_L39_0067CA48);

INCLUDE_ASM("asm/levels", func_L39_0067CAC0);

INCLUDE_ASM("asm/levels", func_L39_0067CCB0);
