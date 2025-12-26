import sys
sys.path.insert(0, r'../build/Debug_x64/312')
import PyBindSample as pbs


def main():
    vec1    = pbs.MyVector(5, 2)
    vec2    = pbs.MyVector(5, 4)
    vec1[3] = 5
    vec3    = vec1 + vec2

    print('{:11} + {:11} = {}'.format('vec1','vec2','vec3'))
    print('{} + {} = {}'.format(vec1, vec2, vec3))

    v = pbs.Vector3(1, 2, 2)
    print(v.length())


if __name__ == '__main__':
    main()
