import tensorflow as tf

sess = tf.Session()

optimizer = tf.train.GradientDescentOptimizer(0.03)

a = tf.Variable([4553.0], tf.float32)
b = tf.Variable([324.0], tf.float32)

sess.run(tf.global_variables_initializer())

x = tf.placeholder(tf.float32)
y = tf.placeholder(tf.float32)

func = a * x + b

deltas = tf.square(func - y)
loss = tf.reduce_sum(deltas)

train_step = optimizer.minimize(loss)

for i in range(100):

	print(sess.run([a, b]))

	sess.run(train_step,{
		x: [-2.0, 0.0, 2.0],
		y: [-7.0, -1.0, 5.0]
	})

print("f(x) = " + str(int(sess.run(a))) + "x + " + str(int(round(sess.run(b)))))