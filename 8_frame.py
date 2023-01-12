import pygame
import os
##########################################################################
# 기본 초기화 ( 반드시 해야하는 것)
pygame.init() 

# 화면 크기 설정
screen_width = 800 # 가로 크기
screen_height = 600 # 세로 크기
screen = pygame.display.set_mode((screen_width,screen_height))

# 화면 타이틀 설정
pygame.display.set_caption("mogakso pang") # 게임 제목 설정

# FPS
clock = pygame.time.Clock()
##########################################################################

# 1. 사용자 게임 초기화 ( 배경화면 , 게임 이미지, 좌표, 속도, 폰트)
current_path = os.path.dirname(_file_)#현재파일위치반환
image_path = os.path.join(current_path, "images")

#배경
background = pygame.image.load(os.path.join(image_path, "background.png"))
stage = pygame.image.load(os.path.join(image_path, "stage.png"))
stage_size = stage.get_rect().size
stage_height = stage_size[1]


character = pygame.image.load(os.path.join(image_path, "character.png"))
character_size = character.get_rect().size # 이미지의 크기를 구해옴
character_width = character_size[0]  # 캐릭터의 가로 크기
character_height = character_size[1] # 캐릭터의 세로 크기
character_x_pos = (screen_width / 2 ) - (character_width / 2) # 화면 가로의 절반 크기에 해당하는 곳에 위치 (가로)
character_y_pos = screen_height - character_height-stage_height # 화면 세로 크기 가장 아래에 해당하는 곳에 위치 (세로)

# 이벤트 루프
running = True # 게임이 진행중인가?
while running :
    dt = clock.tick(30) # 게임화면의 초당 프레임 수를 설정 

# 캐릭터가 100 만크 이동을 해야함
# 10 fps : 1초 동안에 10번 동작 -> 1번에 몇 만큼 이동? 10만큼 ! 10 * 10 = 100
# 20 fps : 1초 동안에 20번 동작 -> 1번에 5만큼 ! 5 * 20 = 100
    print("fps :" + str(clock.get_fps()))
    
    # 2. 이벤트 처리 ( 키보드, 마우스 등)
    for event in pygame.event.get():  # 어떤 이벤트가 발생하였는가?
        if event.type == pygame.QUIT: # 창이 닫히는 이벤트가 발생하였는가?
                running = False # 게임이 진행중이 아님
        
                
        if event.type == pygame.KEYUP: # 방향키를 뗴면 멈춤
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                to_x = 0
            elif event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                to_y = 0
    
    # 3. 게임 캐릭터 위치 정의             
    
    
    
    # 가로 경계값 처리 
    if character_x_pos < 0 :
        character_x_pos = 0
    elif character_x_pos > screen_width - character_width :
        character_x_pos = screen_width - character_width
         
    # 세로 경계값 처리
    if character_y_pos < 0 :
        character_y_pos = 0
    elif character_y_pos > screen_height - character_height:
        character_y_pos =  screen_height - character_height
    
    # 4. 충돌 처리 
    
    # 충돌 처리를 위한 rect 정보 업데아트
    character_rect = character.get_rect()
    character_rect.left = character_x_pos
    character_rect.top = character_y_pos
    
    enemy_rect = enemy.get_rect()
    enemy_rect.left = enemy_x_pos
    enemy_rect.top = enemy_y_pos        
    
    # 충돌 체크
    
    if character_rect.colliderect(enemy_rect) :
        print("충돌 했어요")
        running = False
    
    
    
    
    # 5. 화면에 그리기 
    
            
    #screen.fill((0 ,0 , 255))           
    screen.blit(background, (0,0)) # 배경 그리기
    screen.blit(character, (character_x_pos, character_y_pos)) # 캐릭터 그리기 
    screen.blit(enemy, (enemy_x_pos, enemy_y_pos)) # 적 그리기
    screen.blit(stage,(0,screen_height))
    #타이머 집어 넣기
    #경과 시간 계산
    elapsed_time = (pygame.time.get_ticks() - start_ticks ) / 1000
    # 경과 시간 (ms) 을 1000으로 나누어서 초(s)로 표시
    
    timer = game_font.render(str(int(total_time - elapsed_time)), True,(255,255,255))
    # 출력할 글자 , True, 글자 색상
    screen.blit(timer, (10,10))
    
    # 만약 시간이 0 이하이면 게임 종료
    if total_time - elapsed_time <= 0 :
        print('타임아웃')
        running = False 

    
    # 무조건 해야해 
    pygame.display.update() # 게임화면을 다시 그리기! 
# 잠시 대기
pygame.time.delay(2000) # 2초 정도 대기

    
# pygame 종료
pygame.quit()