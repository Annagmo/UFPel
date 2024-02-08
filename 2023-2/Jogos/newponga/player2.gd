extends CharacterBody2D

@export var a = true
var move = Vector2()
var direction

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.




# warning-ignore:unused_argument
func _physics_process(delta):
	if a:
		if Input.is_key_pressed(KEY_LEFT):
			move.y = -300
		elif Input.is_key_pressed(KEY_RIGHT):
			move.y = 300
		else:
			move.y = 0
	else:
		if Input.is_key_pressed(KEY_Z):
			move.y = -300
		elif Input.is_key_pressed(KEY_X):
			move.y = 300
		else:
			move.y = 0
# warning-ignore:return_value_discarded
	set_velocity(move)
	move_and_slide()


# warning-ignore:unused_argument
func _on_top_child_entered_tree(node):
	pass # Replace with function body.


# warning-ignore:unused_argument
func _on_bott_child_entered_tree(node):
	pass # Replace with function body.


# warning-ignore:unused_argument
func _on_left_child_entered_tree(node):
	pass # Replace with function body.


# warning-ignore:unused_argument
func _on_right_child_entered_tree(node):
	pass # Replace with function body.
