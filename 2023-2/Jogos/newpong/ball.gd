extends CharacterBody2D

var speed = Vector2(300, 30)

# Called when the node enters the scene tree for the first time.
func _ready():
	position.x = 512
	position.y = 250



func _process(delta):
	translate(speed*delta)
	#fucking walls
	if global_position.x > 1037:
		speed.x *= -1
	if global_position.x < 32:
		speed.x *= -1
	if global_position.y > 600:
		speed.y *= -1
	if global_position.y < 0:
		speed.y *= -1




