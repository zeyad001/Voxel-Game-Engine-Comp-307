##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Voxel
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Zeyad\C++\C++CodeLite\Space"
ProjectPath            := "C:\Users\Zeyad\C++\C++CodeLite\Workspace\Voxel"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Zeyad
Date                   :=01/09/2015
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Voxel.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)C:/MinGW/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)glew32s $(LibrarySwitch)glu32 $(LibrarySwitch)opengl32 $(LibrarySwitch)freeglut $(LibrarySwitch)mingw32 $(LibrarySwitch)SDL2main $(LibrarySwitch)SDL2 
ArLibs                 :=  "glew32s" "glu32" "opengl32" "freeglut" "mingw32" "SDL2main" "SDL2" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/MinGW/lib $(LibraryPathSwitch)C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Algorithm.cpp$(ObjectSuffix) $(IntermediateDirectory)/Block.cpp$(ObjectSuffix) $(IntermediateDirectory)/BlockManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Chunk.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Options.cpp$(ObjectSuffix) $(IntermediateDirectory)/Side.cpp$(ObjectSuffix) $(IntermediateDirectory)/Storing.cpp$(ObjectSuffix) $(IntermediateDirectory)/TerrainGen.cpp$(ObjectSuffix) $(IntermediateDirectory)/World.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/EventMessenger.cpp$(ObjectSuffix) $(IntermediateDirectory)/MouseEvent.cpp$(ObjectSuffix) $(IntermediateDirectory)/KeyPressEvent.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Algorithm.cpp$(ObjectSuffix): Algorithm.cpp $(IntermediateDirectory)/Algorithm.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/Algorithm.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Algorithm.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Algorithm.cpp$(DependSuffix): Algorithm.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Algorithm.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Algorithm.cpp$(DependSuffix) -MM "Algorithm.cpp"

$(IntermediateDirectory)/Algorithm.cpp$(PreprocessSuffix): Algorithm.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Algorithm.cpp$(PreprocessSuffix) "Algorithm.cpp"

$(IntermediateDirectory)/Block.cpp$(ObjectSuffix): Block.cpp $(IntermediateDirectory)/Block.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/Block.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Block.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Block.cpp$(DependSuffix): Block.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Block.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Block.cpp$(DependSuffix) -MM "Block.cpp"

$(IntermediateDirectory)/Block.cpp$(PreprocessSuffix): Block.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Block.cpp$(PreprocessSuffix) "Block.cpp"

$(IntermediateDirectory)/BlockManager.cpp$(ObjectSuffix): BlockManager.cpp $(IntermediateDirectory)/BlockManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/BlockManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BlockManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BlockManager.cpp$(DependSuffix): BlockManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BlockManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BlockManager.cpp$(DependSuffix) -MM "BlockManager.cpp"

$(IntermediateDirectory)/BlockManager.cpp$(PreprocessSuffix): BlockManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BlockManager.cpp$(PreprocessSuffix) "BlockManager.cpp"

$(IntermediateDirectory)/Chunk.cpp$(ObjectSuffix): Chunk.cpp $(IntermediateDirectory)/Chunk.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/Chunk.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Chunk.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Chunk.cpp$(DependSuffix): Chunk.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Chunk.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Chunk.cpp$(DependSuffix) -MM "Chunk.cpp"

$(IntermediateDirectory)/Chunk.cpp$(PreprocessSuffix): Chunk.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Chunk.cpp$(PreprocessSuffix) "Chunk.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Options.cpp$(ObjectSuffix): Options.cpp $(IntermediateDirectory)/Options.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/Options.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Options.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Options.cpp$(DependSuffix): Options.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Options.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Options.cpp$(DependSuffix) -MM "Options.cpp"

$(IntermediateDirectory)/Options.cpp$(PreprocessSuffix): Options.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Options.cpp$(PreprocessSuffix) "Options.cpp"

$(IntermediateDirectory)/Side.cpp$(ObjectSuffix): Side.cpp $(IntermediateDirectory)/Side.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/Side.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Side.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Side.cpp$(DependSuffix): Side.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Side.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Side.cpp$(DependSuffix) -MM "Side.cpp"

$(IntermediateDirectory)/Side.cpp$(PreprocessSuffix): Side.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Side.cpp$(PreprocessSuffix) "Side.cpp"

$(IntermediateDirectory)/Storing.cpp$(ObjectSuffix): Storing.cpp $(IntermediateDirectory)/Storing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/Storing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Storing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Storing.cpp$(DependSuffix): Storing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Storing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Storing.cpp$(DependSuffix) -MM "Storing.cpp"

$(IntermediateDirectory)/Storing.cpp$(PreprocessSuffix): Storing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Storing.cpp$(PreprocessSuffix) "Storing.cpp"

$(IntermediateDirectory)/TerrainGen.cpp$(ObjectSuffix): TerrainGen.cpp $(IntermediateDirectory)/TerrainGen.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/TerrainGen.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TerrainGen.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TerrainGen.cpp$(DependSuffix): TerrainGen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TerrainGen.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TerrainGen.cpp$(DependSuffix) -MM "TerrainGen.cpp"

$(IntermediateDirectory)/TerrainGen.cpp$(PreprocessSuffix): TerrainGen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TerrainGen.cpp$(PreprocessSuffix) "TerrainGen.cpp"

$(IntermediateDirectory)/World.cpp$(ObjectSuffix): World.cpp $(IntermediateDirectory)/World.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/World.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/World.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/World.cpp$(DependSuffix): World.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/World.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/World.cpp$(DependSuffix) -MM "World.cpp"

$(IntermediateDirectory)/World.cpp$(PreprocessSuffix): World.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/World.cpp$(PreprocessSuffix) "World.cpp"

$(IntermediateDirectory)/EventMessenger.cpp$(ObjectSuffix): EventMessenger.cpp $(IntermediateDirectory)/EventMessenger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/EventMessenger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EventMessenger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EventMessenger.cpp$(DependSuffix): EventMessenger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EventMessenger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EventMessenger.cpp$(DependSuffix) -MM "EventMessenger.cpp"

$(IntermediateDirectory)/EventMessenger.cpp$(PreprocessSuffix): EventMessenger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EventMessenger.cpp$(PreprocessSuffix) "EventMessenger.cpp"

$(IntermediateDirectory)/MouseEvent.cpp$(ObjectSuffix): MouseEvent.cpp $(IntermediateDirectory)/MouseEvent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/MouseEvent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MouseEvent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MouseEvent.cpp$(DependSuffix): MouseEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MouseEvent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MouseEvent.cpp$(DependSuffix) -MM "MouseEvent.cpp"

$(IntermediateDirectory)/MouseEvent.cpp$(PreprocessSuffix): MouseEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MouseEvent.cpp$(PreprocessSuffix) "MouseEvent.cpp"

$(IntermediateDirectory)/KeyPressEvent.cpp$(ObjectSuffix): KeyPressEvent.cpp $(IntermediateDirectory)/KeyPressEvent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Zeyad/C++/C++CodeLite/Workspace/Voxel/KeyPressEvent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/KeyPressEvent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/KeyPressEvent.cpp$(DependSuffix): KeyPressEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/KeyPressEvent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/KeyPressEvent.cpp$(DependSuffix) -MM "KeyPressEvent.cpp"

$(IntermediateDirectory)/KeyPressEvent.cpp$(PreprocessSuffix): KeyPressEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/KeyPressEvent.cpp$(PreprocessSuffix) "KeyPressEvent.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


