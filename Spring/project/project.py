import time
import turtle

# Initalization Variables

px = 42 # pixel size
sz = 7 # board size
y = 100 # y base
w = 4 # dist from x = 0 line in px
psz = 5 # pen size
ship_set = [2, 3, 3, 4, 5] # ship set

############################ DRAWING SECTION ####################################################################
#########################################



s = turtle.Screen()
t = turtle.Turtle()
t.hideturtle()

def circle(x, y, color):
    t.pensize(w)
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.fillcolor(color)
    t.begin_fill()
    r = 20
    while (r > 0):
        t.circle(r)
        r //= 2
    t.end_fill()

def shipdraw(start_coord, end_coord, length):
    #startcoord should have lower left turtle coordinate corner of the square, and endcoord should have upper right turtle coordinate corner of the square.
    # Also start_coord is the one closer to [1,1].
    t.pensize(1)
    t.penup()
    t.pencolor("orange")
    t.fillcolor('gray')
    t.goto(start_coord[0], start_coord[1])
    t.pd()
    t.begin_fill()
    t.goto(start_coord[0], end_coord[1])
    t.goto(end_coord[0], end_coord[1])
    t.goto(end_coord[0], start_coord[1])
    t.goto(start_coord[0], start_coord[1])
    hz = -(start_coord[0] - end_coord[0])/(length) - 1/2
    vt = -(start_coord[1] - end_coord[1])/(2 * length) - 1/2
    bsx = start_coord[0] + 1/2
    bsy = start_coord[1] + 1/2
    for i in range(length):
        circle(px * (bsx + i * hz - sz - w), y + px * (bsy + i * vt), "grey")
    t.end_fill()


def showyourboard(ships, hit_shots, missed_shots):
    # Makes main square
    t.pu()
    startx = - px * (sz + w)
    starty = y
    t.pencolor("black")
    t.pensize(psz)
    t.fillcolor("teal")
    t.goto(startx, y)
    t.pd()

    # Creates Square
    t.begin_fill()
    for i in range(4):
        t.forward(px * sz)
        t.left(90)
    t.end_fill()

    # Creates Horz Grid Lines
    for i in range(sz + 1):
        t.goto((startx, starty + px*i))
        t.pd()
        t.goto((startx + sz * px, starty + px*i))
        t.pu()

    # Creates Vert Grid Lines
    for i in range(sz + 1):
        t.goto((startx + px * i, starty))
        t.pd()
        t.goto((startx + px * i, starty + sz * px))
        t.pu()

    for ship in ships:
        shipdraw([-px*(w + sz) + px * (ship[0][0] - 1), -y + sz*(ship[0][1] - 1)], 
                 [-px*(w + sz) + sz * ship[1][0]      , -y + sz*(ship[1][1])], 
                 max(abs(ships[1][0] - ships[0][0]), abs(ships[1][1] - ships[0][1])))

    for hit in hit_shots:
        circle(-px*(w + sz)+px*(hit[0])-px/2, -y+px*(hit[1]-1), 'red')

    for miss in missed_shots:
        circle(-px*(w + sz)+px*(miss[0])-px/2, -y+px*(miss[1]-1), 'white')

def showoppboard(hit_shots, missed_shots):
    # Makes main square
    t.pu()
    startx = px * w
    starty = y
    t.pencolor("black")
    t.pensize(psz)
    t.fillcolor("teal")
    t.goto(startx, y)
    t.pd()

    # Creates Square
    t.begin_fill()
    for i in range(4):
        t.forward(px * sz)
        t.left(90)
    t.end_fill()

    # Creates Horz Grid Lines
    for i in range(sz + 1):
        t.goto((startx, starty + px*i))
        t.pd()
        t.goto((startx + sz * px, starty + px*i))
        t.pu()

    # Creates Vert Grid Lines
    for i in range(sz + 1):
        t.goto((startx + px * i, starty))
        t.pd()
        t.goto((startx + px * i, starty + sz * px))
        t.pu()

    for hit in hit_shots:
        circle(-px * (w + sz) + px * hit[0] -px/2, 
               -y + px * (hit[1]-1), 'red')

    for miss in missed_shots:
        circle(-px * (w + sz) + px * miss[0]-px/2, 
               -y + px* (miss[1] - 1), 'white')

############################ CODING SECTION ##############################################################################################################

# Define global variables that will be used during ship selection
count = 0
ship = []

# Function to deal with clicks to choose two endpoints of a ship:
def click_for_ship_selection(clickx, clicky):
    ycoord = int((clicky - y) // px + 1)
    xcoord = int((clickx + px * (sz + w)) // px + 1)
    if 1 <= xcoord <= sz and 1 <= ycoord <= sz:
        ship.append([xcoord, ycoord])
        count += 1

    if count >= 2:
        count = 0
        s.onscreenclick(None)  # Disable the event handler to stop further clicks

def checkshipplace(shiplen, co1, co2, usedships):
    if co1[0] < 1 or co1[0] > sz:
        return False
    if co1[1] < 1 or co1[1] > sz:
        return False
    if co2[0] < 1 or co2[0] > sz:
        return False
    if co2[1] < 1 or co2[1] > sz:
        return False
    if co1[0] == co2[0]:  # vertical
        if shiplen-1 == abs(co1[1]-co2[1]):  # Checks it has right length
            for i in range(co1[1], co2[1]+1):  # Now checks each part of the ship is in an unused coordinate
                if [co1[0], i] in usedships:
                    return False
            return True
        else:
            return False
    elif co1[1] == co2[1]:  # horizontal
        if shiplen-1 == abs(co1[0]-co2[0]):  # Checks it has right length
            for i in range(co1[0], co2[0]+1):  # Now checks each part of the ship is in an unused coordinate
                if [i, co1[1]] in usedships:
                    return False
            return True
        else:
            return False
    else:  # diagonal ship
        return False

def getnames():
    name1, name2 = turtle.textinput("Player names", "Please enter your names, separated by a comma followed by a space (like 'Billy Bob, Goofy Garud'): ").split(", ")
    return name1, name2


############### MAIN CODE #######################

# Begin battleship, opening credits
names = getnames()
p1 = names[0]
p2 = names[1]
rules = turtle.textinput("Welcome message", "Welcome to battleship, my fellow pirates " + str(p1) + ' and ' + str(p2) + '.' + " Here are the rules of the game. \n \n Each player will be given a 7x7 board, and will place four ships with length 2, 3, 4, and 5. Your goal is to sink all of your opponent's ships before they sink yours.\n On a turn, a player will be allowed to guess a coordinate on the opponent's board. If the coordinate is a hit, they will get a red marker on that portion of the board. If the coordinate is a miss, they will get a white marker. You will be notified when you have annihilated an opponent ship.\n The game will end when all of one player's ships are sunk. \n \n Enter anything to acknowledge you understand the rules of the game.")

# P1 places ships

p1_used_ships = []
p1ships = []
showyourboard([], [], [])
showoppboard([], [])
r = turtle.textinput("Ship placement", p1 + " will now place their ships. For each ship, you will click on the 2 coordinates. Please place your length 2 ship, length 3 ship, another length 3, length 4, and length 5, in that order.\n \n Enter anything to continue after reading this message to confirm your partner isn't cheating.")
for i in [2,3,3,4,5]:  ###Places ship of length i
    count = 0
    ship = []
    s.onscreenclick(click_for_ship_selection) #Selects the click handler to deal with sleecting two squares for a shipp
    while count < 2:
        s.update()  # Ensure the screen updates to capture the clicks
    s.onscreenclick(None)  # Disable the event handler after ship is placed

    print(ship)
    while not checkshipplace(i, ship[0], ship[1], p1_used_ships):
        r = turtle.textinput("Error", "The ship you have entered is invalid. Check that the ship is horizontal or vertical, and has length " + str(i) + '. Also make sure it does not pass through any already taken squares. Please click new squares.')
        count = 0
        ship = []
        s.onscreenclick(click_for_ship_selection)
        while count < 2:
            s.update()  # Ensure the screen updates to capture the clicks
        s.onscreenclick(None)  # Disable the event handler after ship is placed
        print(ship)


    ship = sorted(ship, key=lambda x: x[1])
    ship = sorted(ship, key=lambda x: x[0]) # This is to sort the ship in 'increasing' order like [[1,3],[2,3]] rather than the other way around. The key=lambda x: x[n] is used to sort by nth element


    for i in range(ship[0][0], ship[1][0]+1):
        for j in range(ship[0][1], ship[1][1]+1):
            p1_used_ships.append([i, j])
    p1ships.append(ship)

    
    #Now we draw the board for now
    shipdraw([-px*(w + sz) + px * (ship[0][0] - 1), -y + sz*(ship[0][1] - 1)], 
             [-px*(w + sz) + sz * ship[1][0]      , -y + sz*(ship[1][1])], i)

time.sleep(4)

s.clearscreen()


#P2 will now play their board

p2_used_ships = []
p2ships = []
showyourboard([], [], [])
showoppboard([], [])
r = turtle.textinput("Ship placement", p2 + " will now place their ships. For each ship, you will click on the 2 coordinates. Please place your length 2 ship, length 3 ship, another length 3, length 4, and length 5, in that order.\n \n Enter anything to continue after reading this message to confirm your partner isn't cheating.")
for i in ship_set:  ###Places ship of length i
    count = 0
    ship = []
    s.onscreenclick(click_for_ship_selection) #Selects the click handler to deal with selecting two squares for a ship
    while count < 2:
        s.update()  # Ensure the screen updates to capture the clicks
    s.onscreenclick(None)  # Disable the event handler after ship is placed
    print(ship)
    
    while not checkshipplace(i, ship[0], ship[1], p2_used_ships):
        r = turtle.textinput("Error", "The ship you have entered is invalid. Check that the ship is horizontal or vertical, and has length " + str(i) + '. Also make sure it does not pass through any already taken squares. Please click new squares.')
        count = 0
        ship = []
        s.onscreenclick(click_for_ship_selection)
        while count < 2:
            s.update()  # Ensure the screen updates to capture the clicks
        s.onscreenclick(None)  # Disable the event handler after ship is placed
        print(ship)

    ship = sorted(ship, key=lambda x: x[1])
    ship = sorted(ship, key=lambda x: x[0]) # This is to sort the ship in 'increasing' order like [[1,3],[2,3]] rather than the other way around. The key=lambda x: x[n] is used to sort by nth element


    for i in range(ship[0][0], ship[1][0]+1):
        for j in range(ship[0][1], ship[1][1]+1):
            p2_used_ships.append([i, j])
    p2ships.append(ship)


    #Now we draw the board for now
    shipdraw([-px*(w + sz) + px * (ship[0][0] - 1), y + sz*(ship[0][1] - 1)], 
             [-px*(w + sz) + sz * ship[1][0]      , y + sz*(ship[1][1])], 
             max(abs(ship[1][0] - ship[0][0]), abs(ship[1][1] - ship[0][1])))



#Now both players have placed their ships, we can start the game

p1hits = []
p1miss = []
p2hits = []
p2miss = []