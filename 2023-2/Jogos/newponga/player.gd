extends CharacterBody2D


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

@export var a = true

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.



func _physics_process(delta):
	var directions
	
	if a:
		directions = Input.get_axis("ui_up", "ui_down")
	else:
		directions = Input.get_axis("ui_Z", "ui_X")
