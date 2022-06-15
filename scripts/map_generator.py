import numpy as np
import random
import sys

matrix_height = 10
matrix_width = 0
start_coord = (0, 0, 0)

blocks = [
    "air",
    "grass_block",
    "dirt",
    "coarse_dirt",
    "stone",
    "cobblestone",
    "coal_ore",
    "copper_ore",
    "bookshelf",
    "dead_bush",
    "gravel"
]

block_matrix = []

custom_blocks = []


def print_help():
    print("Usage:")
    print("python3 main.py start_x, start_y, start_z, square_size")
    print("Example (used in the project):")
    print("python3 main.py -28 -4.5 -20 39 > output.txt")


# These block doesn't belong in the matrix
def add_custom_block(block_name):
    pass


def set_block(x, y, z, block_idx):
    block_matrix[z][y][x] = block_idx


def get_block_by_name(block_name):
    for idx, block in enumerate(blocks):
        if block == block_name:
            return idx
    raise ValueError("Block not found")


def populate_layer(layer_number, block_percentage):
    for y in range(matrix_width):
        for x in range(matrix_width):
            random_int = random.randint(0, 100)
            for key, value in block_percentage.items():
                if value[0] <= random_int <= value[1]:
                    set_block(x, y, layer_number, get_block_by_name(key))
                    break


def count_successive_blocks(x, y, z):
    block_idx = int(block_matrix[z][y][x])

    count = 1
    for i in range(x + 1, matrix_width):
        if int(block_matrix[z][y][i]) == block_idx:
            count += 1
        else:
            break
    return count


def dump_matrix():
    for z in range(matrix_height):
        for y in range(matrix_width):
            x = 0
            while x < matrix_width:
                count = count_successive_blocks(x, y, z)
                if int(block_matrix[z][y][x]) != 0:
                    print(f"{x + (count - 1) + start_coord[0]} {z + start_coord[1]} {y + start_coord[2]} {count} 1 {blocks[int(block_matrix[z][y][x])]}")
                x += count


def set_custom_block(coord, coord_deepness, block_idx):
    for z in range(coord[2], coord[2] + coord_deepness[2]):
        for y in range(coord[1], coord[1] + coord_deepness[1]):
            for x in range(coord[0], coord[0] + coord_deepness[0]):
                block_matrix[z][y][x] = block_idx


def place_custom_blocks():
    pass


def main():
    global start_coord
    global matrix_height
    global matrix_width
    global block_matrix
    argv = sys.argv
    argc = len(argv)

    if argc != 5:
        print_help()
        sys.exit(84)
    try:
        start_coord = (float(argv[1]), float(argv[2]), float(argv[3]))
        matrix_width = int(argv[4])
    except ValueError:
        print_help()
        sys.exit(84)
    block_matrix = np.zeros((matrix_height, matrix_width, matrix_width))

    populate_layer(4, {
        "gravel": (0, 6),
        "coarse_dirt": (7, 17),
        "dirt": (18, 28),
        "grass_block": (29, 100),
    })
    populate_layer(3, {
        "dirt": (0, 100),
    })
    populate_layer(2, {
        "stone": (0, 20),
        "dirt": (21, 100),
    })
    populate_layer(1, {
        "stone": (0, 80),
        "copper_ore": (81, 90),
        "coal_ore": (91, 100),
    })
    populate_layer(0, {
        "stone": (0, 80),
        "copper_ore": (81, 90),
        "coal_ore": (91, 100),
    })
    place_custom_blocks()
    dump_matrix()


if __name__ == '__main__':
    main()
