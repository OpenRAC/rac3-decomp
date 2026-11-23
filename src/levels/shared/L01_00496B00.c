#include "common.h"

typedef struct Obj_4917A0 Obj_4917A0;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_4917A0 *);
} Vt_4917A0;
struct Obj_4917A0 {
    s32 pad;
    Vt_4917A0 *vt;
};
typedef struct S_492AF0 S_492AF0;
typedef struct { u8 pad[0xC]; void (*fC)(S_492AF0 *); } V_492AF0;
struct S_492AF0 { s32 f0; V_492AF0 *vt; };
typedef struct Obj_492EE8 Obj_492EE8;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_492EE8 *);
} Vt_492EE8;
struct Obj_492EE8 {
    s32 pad;
    Vt_492EE8 *vt;
};

/* localdecomp:start func_L01_00496B00 */
typedef struct { s32 a, b, c, d; } Q_496B00;
extern Q_496B00 D_L01_001D91B8;
extern s32 func_L01_00518D40_00496B00(s32);
extern void func_L01_00496B60(s32, Q_496B00 *);
extern void func_L01_005176C8(s32, s32);

void func_L01_00496B00(void) {
    Q_496B00 q;

    func_L01_00518D40_00496B00(0x470000);
    q = D_L01_001D91B8;
    func_L01_00496B60(0x470000, &q);
    func_L01_005176C8(0xE, 0x470000);
}
/* localdecomp:end func_L01_00496B00 */
