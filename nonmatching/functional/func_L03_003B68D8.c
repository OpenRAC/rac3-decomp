/* functional: medium. Jump table jtbl_002BE500 (0->69C8, 1->6B90, 2->6BE4, 3,>=7->frame++ only, 4->6BB8, 5->692C, 6->6C0C). vector basis helpers func_0038CE90/CE68 inferred as cross/normalise-in-place (return ignored). vadd/vsub.xyz as plain float math. */
/* localdecomp:start func_L03_003B68D8 */
typedef int Q_3B68D8 __attribute__((mode(TI)));
typedef struct { f32 f[4]; } __attribute__((aligned(16))) V_3B68D8;
static void vadd3(f32 *d, f32 *a, f32 *b) { d[0] = a[0] + b[0]; d[1] = a[1] + b[1]; d[2] = a[2] + b[2]; d[3] = a[3]; }
static void vsub3(f32 *d, f32 *a, f32 *b) { d[0] = a[0] - b[0]; d[1] = a[1] - b[1]; d[2] = a[2] - b[2]; d[3] = a[3]; }
__asm__(".extern D_001DEA54_sda, 4");
__asm__(".extern D_001DEA5C_sda, 4");
__asm__(".extern D_001DEA58_sda, 4");
__asm__(".extern D_001DEA4C_sda, 4");
__asm__(".extern D_001DEA48_sda, 4");
__asm__(".extern D_001DEA50_sda, 4");
__asm__(".extern D_001DEA3C_sda, 4");
__asm__(".extern D_001DEA40_sda, 4");
__asm__(".extern D_001DEA44_sda, 4");
__asm__(".extern D_001DEA60_sda, 4");
extern f32 D_001DEA54_sda;
extern f32 D_001DEA5C_sda;
extern s32 D_001DEA58_sda;
extern f32 D_001DEA4C_sda;
extern f32 D_001DEA48_sda;
extern f32 D_001DEA50_sda;
extern s32 D_001DEA3C_sda;
extern s32 D_001DEA40_sda;
extern s32 D_001DEA44_sda;
extern f32 D_001DEA60_sda;
extern void func_L03_003B7458(u8 *);
extern void func_L03_003B6F98(void *);
extern void func_L03_003ADB38(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C48A8(void *, void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_00404808(void (*)(void *), u8 *);
extern s32 func_L01_004561B8(u8 *);
extern void func_003C2880(u8 *);

void func_L03_003B68D8(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    V_3B68D8 v0, v1, v2, v3, v4;
    V_3B68D8 arr[3];
    u8 *owner;
    switch (m[0x20]) {
    case 5:
        func_L03_003B7458(m);
        *(Q_3B68D8 *)&v0 = *(Q_3B68D8 *)(m + 0xE0);
        func_0038CF68(&v0, &v0, -D_001DEA54_sda);
        vadd3((f32 *)(m + 0x10), v0.f, (f32 *)(m + 0x10));
        *(Q_3B68D8 *)&v1 = *(Q_3B68D8 *)(m + 0xE0);
        *(f32 *)(s + 0x48) = *(f32 *)(s + 0x48) + D_001DEA5C_sda;
        func_0038CF68(&v1, &v1, *(f32 *)(s + 0x48));
        vadd3((f32 *)(m + 0x10), v1.f, (f32 *)(m + 0x10));
        if (!(*(u16 *)(m + 0x96) < D_001DEA58_sda)) {
            *(s32 *)(s + 0x48) = 0;
            func_L01_004450F0(m, 0, -1);
        }
        func_L01_00404808(func_L03_003B6F98, m);
        break;
    case 0:
        func_003C2F58(*(void **)(s + 0x28), *(s32 *)(s + 0x30), s + 0x10);
        func_003C2F58(*(void **)(s + 0x28), *(s32 *)(s + 0x30) + 0x20, s);
        *(f32 *)(s + 0x24) = *(f32 *)(s + 0x24) + *(f32 *)(s + 0x20);
        func_003C2F58(*(void **)(s + 0x28), 0x40, &v4);
        vsub3(v1.f, v4.f, (f32 *)(s + 0x10));
        func_0038CF68(&v1, &v1, D_001DEA4C_sda);
        vsub3(v0.f, (f32 *)s, (f32 *)(s + 0x10));
        func_0038CF68(&v2, &v0, D_001DEA48_sda);
        func_0038CF68(&v0, &v0, *(f32 *)(s + 0x24));
        vadd3((f32 *)(m + 0x10), (f32 *)(s + 0x10), v0.f);
        func_0038CE90(&v3, &v1, &v2);
        func_0038CF68(&v3, &v3, D_001DEA50_sda);
        func_0038CE68(&v1, &v2);
        func_0038CE68(&v2, &v3);
        func_0038CE68(&v3, &v1);
        arr[D_001DEA3C_sda] = v2;
        arr[D_001DEA40_sda] = v1;
        arr[D_001DEA44_sda] = v3;
        func_003C48A8(arr, m + 0xF0, &arr[D_001DEA40_sda], &arr[D_001DEA44_sda]);
        *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), 1.5707964f);
        func_0038D308(m + 0xC0, m + 0xF0);
        if (func_0038CF38(m + 0x10, s) <= *(f32 *)(s + 0x20) * 0.88f) {
            func_L01_004450F0(m, 6, -1);
        }
        m[0xA8] = 0xFF;
        func_L01_00404808(func_L03_003B6F98, m);
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) *(s32 *)(m + 0x98) = 0;
        func_L01_00404808(func_L03_003B6F98, m);
        break;
    case 4:
        m[0x31] = 1;
        *(u16 *)(m + 0x34) &= 0xFFFE;
        func_L01_004450F0(m, 0, -1);
        break;
    case 2:
        owner = *(u8 **)(m + 0xB8);
        if (owner != 0 && *(s16 *)(owner + 0xAA) == 0x1AE0) func_L03_003ADB38(owner);
        func_003C2880(m);
        return;
    case 6:
        func_L03_003B7458(m);
        *(Q_3B68D8 *)&v0 = *(Q_3B68D8 *)(m + 0xE0);
        *(f32 *)(s + 0x48) = *(f32 *)(s + 0x48) - D_001DEA60_sda;
        func_0038CF68(&v0, &v0, *(f32 *)(s + 0x48));
        vadd3((f32 *)(m + 0x10), v0.f, (f32 *)s);
        if (*(u16 *)(m + 0x96) < D_001DEA58_sda) {
            func_L01_00404808(func_L03_003B6F98, m);
        } else {
            *(s32 *)(s + 0x48) = 0;
            func_003C2880(m);
            return;
        }
        break;
    default:
        break;
    }
    *(u16 *)(m + 0x96) = *(u16 *)(m + 0x96) + 1;
}
/* localdecomp:end func_L03_003B68D8 */
