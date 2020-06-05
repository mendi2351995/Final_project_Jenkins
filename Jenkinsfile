pipeline {
  agent { node { label 'slave01' } }

   stages {
      stage('Clone Sources') {
        steps {
          checkout scm
        } 
      }
	stage('Build') {
         steps {
            echo 'Build process..'            
            sh '''
                cd /home/slave/workspace/finel_project/scripts
                chmod 755 *.sh
		chmod 755 *.py
		chmod 755 *.c
		chmod 755 *.java
            '''
         }
      }      
        stage("Env Variables") {
            steps {
                sh "printenv"
            }
        }
	 stage('Bash') 
	   {
		 when{
			 expression { Language == 'BASH' || Language == 'ALL'}
		 }
		 steps {
			 echo 'Execute bash script'
			 sh '''
		      	    echo "Testing input string $PARAM"
			    cd /home/slave/workspace/finel_project/scripts
			    ./bash.sh $PARAM
			 '''
		 }	
          }
	   stage ('PYTHON') 
	   {
      		when {
                expression { Language == 'PYTHON' || Language == 'ALL'}
            	}
            	steps {
                	sh '''
		          echo "Execute python script"
		      	  echo "Testing input string $PARAM" 
            	          cd /home/slave/workspace/finel_project/scripts
                          python python.py $PARAM
                          python python.py $PARAM >> /home/slave/results
			'''
            	}
    	   }
	   stage ('C') 
	   {
      		when {
                expression { Language == 'C' || Language == 'ALL'}
            	}
            	steps {
                	sh '''
			  echo 'Execute C script'
			  echo "Testing input string $PARAM"
			  cd /home/slave/workspace/finel_project/scripts
			  ./Cfile.c $PARAM
			  ./Cfile.c $PARAM >> /home/slave/results
			'''
            	}
    	   }
	   stage ('javaFile') 
	   {
      		when {
                expression { Language == 'JAVA' || Language == 'ALL'}
            	}
            	steps {
                	sh '''
			  echo "Execute javaFile script"
			  cd /home/slave/workspace/finel_project/scripts
			  ./javaFile.py $PARAM
			  ./javaFile.py $PARAM >> results
			'''
            	}
    	   }
	stage('Saving Results') {
         steps {
            echo 'Saving Results process..'
            sh '''
	      report_file="${HOME}/Documents/Deployment/report"
              mkdir -p ${HOME}/Documents/Deployment/              
              if [ -f "${report_file}" ]; then
                echo "file ${report_file} exists"
              else
	              touch ${report_file}
              fi  
	      echo "Build Number $BUILD_NUMBER" >> ${report_file}
              cat ${WORKSPACE}/scripts/results >> ${report_file}
	      echo "#############################" >> ${report_file}
            '''
         }
      }	   
      
   }
	post {   
		always {
			echo 'I run scripts in the gob'   
		}   
		success {   
			echo 'I run script Successfully'   
		}   
		failure {
			echo 'I couldnt run the script'
		}   
		unstable {   
			echo 'I will only get executed if this is unstable'   
		}   
	}
}
