#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L13_003C5838 */
typedef struct {
    u8 pad0[0x240];
    s32 f240;
    u8 pad244[0xC];
    s32 f250;
    u8 pad254[0xC];
    s32 f260;
} S_003C5838;
extern void func_L01_00443B18(void *, f32);
extern void func_L01_00450DE8(void *, void *, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00443FB0(void *, void *);
extern u8 *func_L01_0030F288(void *, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00459C50(s32);
extern void func_L01_0044D360(void *, s32, s32, s32, s32, s32, f32);
extern u8 D_001D54C0;
extern s32 D_L13_001E1B18;

void func_L13_003C5838(u8 *self) {
    S_003C5838 *st = *(S_003C5838 **)(self + 0x68);
    vu0_v4 b;
    vu0_v4 a;
    s32 c;
    u8 *r;

    func_L01_00443B18(&a, 0.5f);
    func_L01_00450DE8(self, &b, 0.0f, -1.5f, 1.0f);
    vec_add_ab(&b, &a, &b);
    switch (st->f240) {
    case 0:
        func_003A52A0(3, 0, self);
        break;
    case 1:
        func_003A52A0(2, 0, self);
        func_L01_0044D360(self, 0x32, 0xFA, 3, -1, 0, 0.0f);
        break;
    case 4:
        func_003A52A0(2, 0, self);
        func_L01_00443FB0(self, &c);
        r = func_L01_0030F288(&b, c, -1, 0);
        func_0038CE20(*(void **)(r + 0x68), *(void **)(r + 0x68), 0.35f);
        break;
    case 3:
        st->f250 = 1;
        break;
    case 2:
        func_003A52A0(2, 0, self);
        if (D_001D54C0 == 0) {
            func_L01_00459C50(0x10);
            func_L01_0044D360(self, 0x61A8, 0x61A8, 3, -1, 0, 0.0f);
        } else {
            func_L01_0044D360(self, 0x5DC, 0x5DC, 3, -1, 0, 0.0f);
        }
        break;
    }
    st->f260 = st->f240 == 2;
    D_L13_001E1B18 = 0;
}
/* localdecomp:end func_L13_003C5838 */
