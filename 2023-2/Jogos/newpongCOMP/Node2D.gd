extends Node2D


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

@onready var P1score_label = $Lp1
@onready var P2score_label = $Lp2
@onready var ball = $Ball

var P1score = 0
var P2score = 0

# Called when the node enters the scene tree for the first time.
func _ready():
	P1score_label.text = "0"
	P2score_label.text = "0"

func update_label():
	P1score_label.text = str(P1score)
	P2score_label.text = str(P2score)
	


# warning-ignore:unused_argument
func _on_left_body_entered(body):
	P2score += 1
	update_label()


# warning-ignore:unused_argument
func _on_right_body_entered(body):
	P1score += 1
	update_label()



func _on_bott_child_entered_tree(node):
	pass # Replace with function body.


func _on_top_child_entered_tree(node):
	pass # Replace with function body.
