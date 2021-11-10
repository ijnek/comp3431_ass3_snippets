(define (domain turtlebot3-domain)

  (:types
    room robot item
  )

  (:predicates
    (at ?rbt - robot ?rm - room)
    (in ?itm - item ?rm - room)
    (holding ?rbt - robot ?itm - item)
    (hand_empty ?rbt - robot)
  )

  (:action move
    :parameters (?rbt - robot ?from - room ?to - room)
    :precondition ; Fill out this
    :effect ; Fill out this
  )

  (:action pick
    :parameters(?rbt - robot ?rm - room ?itm - item)
    :precondition ; Fill out
    :effect ; Fill out this
  )

  (:action place
    :parameters(?rbt - robot ?rm - room ?itm - item)
    :precondition ; Fill out this
    :effect ; Fill out this
  )
)