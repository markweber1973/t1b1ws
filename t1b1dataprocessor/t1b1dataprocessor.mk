##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=t1b1dataprocessor
ConfigurationName      :=Debug
WorkspacePath          := "/home/mark/t1b1workspace"
ProjectPath            := "/home/mark/t1b1workspace/t1b1dataprocessor"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Mark
Date                   :=01/04/14
CodeLitePath           :="/home/mark/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
ObjectsFileList        :="t1b1dataprocessor.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lboost_system
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mysqlcppconn 
ArLibs                 :=  "libmysqlcppconn.a" 
LibPath                := $(LibraryPathSwitch)/usr/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -std=c++0x $(Preprocessors)
CFLAGS   :=  -g -std=c++0x $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/climber$(ObjectSuffix) $(IntermediateDirectory)/databaseconnector$(ObjectSuffix) $(IntermediateDirectory)/scorecard$(ObjectSuffix) $(IntermediateDirectory)/enrolledclimber$(ObjectSuffix) $(IntermediateDirectory)/boulderscore$(ObjectSuffix) $(IntermediateDirectory)/primitivescore$(ObjectSuffix) $(IntermediateDirectory)/totalscore$(ObjectSuffix) $(IntermediateDirectory)/primitivetotalscore$(ObjectSuffix) $(IntermediateDirectory)/round$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessor/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/climber$(ObjectSuffix): climber.cpp $(IntermediateDirectory)/climber$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessor/climber.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/climber$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/climber$(DependSuffix): climber.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/climber$(ObjectSuffix) -MF$(IntermediateDirectory)/climber$(DependSuffix) -MM "climber.cpp"

$(IntermediateDirectory)/climber$(PreprocessSuffix): climber.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/climber$(PreprocessSuffix) "climber.cpp"

$(IntermediateDirectory)/databaseconnector$(ObjectSuffix): databaseconnector.cpp $(IntermediateDirectory)/databaseconnector$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessor/databaseconnector.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/databaseconnector$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/databaseconnector$(DependSuffix): databaseconnector.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/databaseconnector$(ObjectSuffix) -MF$(IntermediateDirectory)/databaseconnector$(DependSuffix) -MM "databaseconnector.cpp"

$(IntermediateDirectory)/databaseconnector$(PreprocessSuffix): databaseconnector.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/databaseconnector$(PreprocessSuffix) "databaseconnector.cpp"

$(IntermediateDirectory)/scorecard$(ObjectSuffix): scorecard.cpp $(IntermediateDirectory)/scorecard$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessor/scorecard.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scorecard$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scorecard$(DependSuffix): scorecard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scorecard$(ObjectSuffix) -MF$(IntermediateDirectory)/scorecard$(DependSuffix) -MM "scorecard.cpp"

$(IntermediateDirectory)/scorecard$(PreprocessSuffix): scorecard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scorecard$(PreprocessSuffix) "scorecard.cpp"

$(IntermediateDirectory)/enrolledclimber$(ObjectSuffix): enrolledclimber.cpp $(IntermediateDirectory)/enrolledclimber$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessor/enrolledclimber.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/enrolledclimber$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/enrolledclimber$(DependSuffix): enrolledclimber.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/enrolledclimber$(ObjectSuffix) -MF$(IntermediateDirectory)/enrolledclimber$(DependSuffix) -MM "enrolledclimber.cpp"

$(IntermediateDirectory)/enrolledclimber$(PreprocessSuffix): enrolledclimber.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/enrolledclimber$(PreprocessSuffix) "enrolledclimber.cpp"

$(IntermediateDirectory)/boulderscore$(ObjectSuffix): boulderscore.cpp $(IntermediateDirectory)/boulderscore$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessor/boulderscore.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/boulderscore$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/boulderscore$(DependSuffix): boulderscore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/boulderscore$(ObjectSuffix) -MF$(IntermediateDirectory)/boulderscore$(DependSuffix) -MM "boulderscore.cpp"

$(IntermediateDirectory)/boulderscore$(PreprocessSuffix): boulderscore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/boulderscore$(PreprocessSuffix) "boulderscore.cpp"

$(IntermediateDirectory)/primitivescore$(ObjectSuffix): primitivescore.cpp $(IntermediateDirectory)/primitivescore$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessor/primitivescore.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/primitivescore$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/primitivescore$(DependSuffix): primitivescore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/primitivescore$(ObjectSuffix) -MF$(IntermediateDirectory)/primitivescore$(DependSuffix) -MM "primitivescore.cpp"

$(IntermediateDirectory)/primitivescore$(PreprocessSuffix): primitivescore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/primitivescore$(PreprocessSuffix) "primitivescore.cpp"

$(IntermediateDirectory)/totalscore$(ObjectSuffix): totalscore.cpp $(IntermediateDirectory)/totalscore$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessor/totalscore.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/totalscore$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/totalscore$(DependSuffix): totalscore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/totalscore$(ObjectSuffix) -MF$(IntermediateDirectory)/totalscore$(DependSuffix) -MM "totalscore.cpp"

$(IntermediateDirectory)/totalscore$(PreprocessSuffix): totalscore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/totalscore$(PreprocessSuffix) "totalscore.cpp"

$(IntermediateDirectory)/primitivetotalscore$(ObjectSuffix): primitivetotalscore.cpp $(IntermediateDirectory)/primitivetotalscore$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessor/primitivetotalscore.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/primitivetotalscore$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/primitivetotalscore$(DependSuffix): primitivetotalscore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/primitivetotalscore$(ObjectSuffix) -MF$(IntermediateDirectory)/primitivetotalscore$(DependSuffix) -MM "primitivetotalscore.cpp"

$(IntermediateDirectory)/primitivetotalscore$(PreprocessSuffix): primitivetotalscore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/primitivetotalscore$(PreprocessSuffix) "primitivetotalscore.cpp"

$(IntermediateDirectory)/round$(ObjectSuffix): round.cpp $(IntermediateDirectory)/round$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessor/round.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/round$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/round$(DependSuffix): round.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/round$(ObjectSuffix) -MF$(IntermediateDirectory)/round$(DependSuffix) -MM "round.cpp"

$(IntermediateDirectory)/round$(PreprocessSuffix): round.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/round$(PreprocessSuffix) "round.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/climber$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/climber$(DependSuffix)
	$(RM) $(IntermediateDirectory)/climber$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/databaseconnector$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/databaseconnector$(DependSuffix)
	$(RM) $(IntermediateDirectory)/databaseconnector$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/scorecard$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/scorecard$(DependSuffix)
	$(RM) $(IntermediateDirectory)/scorecard$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/enrolledclimber$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/enrolledclimber$(DependSuffix)
	$(RM) $(IntermediateDirectory)/enrolledclimber$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/boulderscore$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/boulderscore$(DependSuffix)
	$(RM) $(IntermediateDirectory)/boulderscore$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/primitivescore$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/primitivescore$(DependSuffix)
	$(RM) $(IntermediateDirectory)/primitivescore$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/totalscore$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/totalscore$(DependSuffix)
	$(RM) $(IntermediateDirectory)/totalscore$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/primitivetotalscore$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/primitivetotalscore$(DependSuffix)
	$(RM) $(IntermediateDirectory)/primitivetotalscore$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/round$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/round$(DependSuffix)
	$(RM) $(IntermediateDirectory)/round$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/t1b1dataprocessor"


