from PIL import Image
import numpy as np

# Set the dimensions of the image
width, height = 256, 256

# Generate a random array of pixel data
pixel_data = np.random.randint(0, 256, (height, width, 3), dtype=np.uint8)

# Create an image from the pixel data
image = Image.fromarray(pixel_data, 'RGB')

# Save the image
image.save('random_image.png')

# Display the image
image.show()
