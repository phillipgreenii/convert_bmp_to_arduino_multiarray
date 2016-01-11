from PIL import Image
import numpy as np
im = Image.open("MioSmallHead.bmp")
p = np.array(im)


def convertArrayTo16bitValue(c):
    r = c[0] >> 3
    g = c[1] >> 2
    b = c[2] >> 3
    return (r << 11) | (g << 5) | b


def main():
    f = []
    for row in p:
        r = []
        for c in row:
            v = convertArrayTo16bitValue(c)
            r.append("0x" + format(v, '02x'))
            # r.append(format(v, 'd'))
        f.append(" {" + ",".join(r) + "}")

    s = "uint16_t bmp[][20] = {\n" + ",\n".join(f) + "\n};"

    with open('bmp/bmp.h', 'w') as o:
        o.write(s)

if __name__ == '__main__':
    main()
