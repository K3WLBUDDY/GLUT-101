#include "DShader.h"

void DShader::compileShader(std::string& filePath)
{

  const char *fp = filePath.c_str();;
  //std::cout<<"\n Reached this too";
  std::ifstream shaderCode (fp);
  if(shaderCode.fail())
  {
    perror(fp);
    std::cout<<"\n Failed to Open " <<fp;
  }
  std::string code="";
  std::string line;

  int pathLen = strlen(fp);
  int extBuffer = pathLen-2;

  std::string ext=filePath.substr(extBuffer, 2);

  if(ext.compare("vs") == 0)
  {
    _vs = glCreateShader(GL_VERTEX_SHADER);
    std::cout<<"\n Created VS";

    if(_vs == 0)
    {
       std::cout<<"\n Failed to Create Vertex Shader";
    }

    else
    {
      while(getline(shaderCode, line))
      {
        code += line+"\n";
      }
      shaderCode.close();

      const char* contentPtr = code.c_str();

      glShaderSource(_vs, 1, &contentPtr, nullptr);
      glCompileShader(_vs);

      GLint success =0;

      glGetShaderiv(_vs, GL_COMPILE_STATUS, &success);

      if(success == GL_FALSE)
      {
        GLint maxLen=0;
        glGetShaderiv(_vs, GL_INFO_LOG_LENGTH, &maxLen);

        std::vector<char> errorLog(maxLen);
        glGetShaderInfoLog(_vs, maxLen, &maxLen, &errorLog[0]);

        glDeleteShader(_vs);

        printf("\n%s", &errorLog[0]);

        std::cout<<"\n Failed to Compile Vertex Shader";

        SDL_Quit();
      }
    }


  }
  else if(ext.compare("fs") == 0)
  {
    _fs = glCreateShader(GL_FRAGMENT_SHADER);
    std::cout<<"\n Created FS";

    if(_fs == 0)
    {
       std::cout<<"\n Failed to Create Fragment Shader";
    }

    else
    {
      while(getline(shaderCode, line))
      {
        code += line+"\n";
      }
      shaderCode.close();

      const char* contentPtr = code.c_str();

      glShaderSource(_fs, 1, &contentPtr, nullptr);
      glCompileShader(_fs);

      GLint success =0;

      glGetShaderiv(_fs, GL_COMPILE_STATUS, &success);

      if(success == GL_FALSE)
      {
        GLint maxLen=0;
        glGetShaderiv(_fs, GL_INFO_LOG_LENGTH, &maxLen);

        std::vector<char> errorLog(maxLen);
        glGetShaderInfoLog(_fs, maxLen, &maxLen, &errorLog[0]);

        glDeleteShader(_fs);

        printf("\n%s", &errorLog[0]);

        std::cout<<"\n Failed to Compile Fragment Shader";

        SDL_Quit();
      }
    }
  }
}


void DShader::linkShader()
{

  _pID = glCreateProgram();
  //Attach our shaders to our program
	glAttachShader(_pID, _vs);
	glAttachShader(_pID, _fs);

	//Link our program
	glLinkProgram(_pID);

	//Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(_pID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_pID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<char> infoLog(maxLength);
		glGetProgramInfoLog(_pID, maxLength, &maxLength, &infoLog[0]);

		//We don't need the program anymore.
		//glDeleteProgram(_pID);
		//Don't leak shaders either.
		glDeleteShader(_vs);
		glDeleteShader(_fs);


		//Use the infoLog as you see fit.
		printf("%s\n", &(infoLog[0]));
		std::cout<<"\n Shader failed to Link";

  }
  std::cout<<"\n LINK SUCCESSFULL";
}

void DShader::use()
{
  glUseProgram(_pID);
}

/*void DShader::unuse()
{

}*/
