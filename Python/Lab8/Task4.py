from PIL import Image
import numpy as np

def bw_convert(url):
    image = Image.open(url)
    array = np.asarray(image, dtype='uint8')
    k = np.array([0.2989, 0.587, 0.114])

    width, height, _ = array.shape
    array.reshape(width * height, 3)

    out = np.matmul(array, k)
    out.reshape(width, height)

    image_out = Image.fromarray(out.astype(np.uint8))
    image_out.save("/Users/ivanrovkov/Desktop/Homework/Python/Lab8/res/convertedPony.jpg")

bw_convert("/Users/ivanrovkov/Desktop/Homework/Python/Lab8/res/pony.jpg")  