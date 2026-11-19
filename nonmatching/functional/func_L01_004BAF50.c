/* functional: high. Marks menu pages 1..4 as present: page 1 always, page 2/3/4 when the flag bytes D_00142CC1 / D_00142700 / D_001D5576 are non-zero (each via func_L01_004BAE90, which sets the page bit). */
extern u8 D_00142CC1;
extern u8 D_00142700;
extern u8 D_001D5576;

void func_L01_004BAF50(void) {
    func_L01_004BAE90(1);
    if (D_00142CC1 != 0) {
        func_L01_004BAE90(2);
    }
    if (D_00142700 != 0) {
        func_L01_004BAE90(3);
    }
    if (D_001D5576 != 0) {
        func_L01_004BAE90(4);
    }
}
