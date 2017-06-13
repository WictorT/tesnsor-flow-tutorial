import tensorflow as tf
import sys
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)

count = 0;

for arg in range(1, len(sys.argv)):
	print mnist.validation.labels[int(arg)];
	for i in mnist.validation.images[int(arg)]:
		count += 1;
		sys.stdout.write(str(int(round(i))))
		if count % 28 == 0 :		
			print ""

images, labels = mnist.train.next_batch(1)
print labels