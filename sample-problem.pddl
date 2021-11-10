(define (problem moveitemtoroom)
  (:domain turtlebot3-domain)
  (:objects
    turtlebot - robot
    initial-room - room
    living-room - room
    kitchen - room
    apple banana - item
  )

  (:init
    (at turtlebot initial-room)
    (in apple kitchen)
    (in banana living-room)
    (hand_empty turtlebot)
  )

  (:goal
    (in apple living-room)
  )
)