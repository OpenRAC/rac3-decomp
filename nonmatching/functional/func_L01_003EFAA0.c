/* functional: medium. Hand-written VU0 macro-mode bilinear interpolation (retail uses pextlw/pcpyld/qmtc2 and vmul/vadday/vmaddaz/vmaddw): result = ((w0*c0 + w1*c1) + w2*c2) + w3*c3 with w = ((1-a)(1-b), a(1-b), (1-a)b, ab) and c = the four floats at *corners. Written as plain C in the same operation order; VU rounding (truncation, no denormals) may differ in the last bit from the host's. */
f32 func_L01_003EFAA0(f32 *corners, f32 a, f32 b) {
    f32 w0 = (1.0f - a) * (1.0f - b);
    f32 w1 = a * (1.0f - b);
    f32 w2 = (1.0f - a) * b;
    f32 w3 = a * b;
    return ((w0 * corners[0] + w1 * corners[1]) + w2 * corners[2]) + w3 * corners[3];
}
